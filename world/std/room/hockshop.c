// /std/room/hockshop.c
//hockshop.c updated by sbaa
#include <ansi.h>
#define MAX_PAWN_NUM	11
 
inherit ROOM;
 
void init()
{
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem","redeem");
}
 
string value_string(int value)
{
        if( value < 1 ) value = 1;
        else if( value < 100 )
           return chinese_number(value) + "文钱";
        else   
           return chinese_number(value/100) + "两白银"
           + (value%100? "又" + chinese_number(value%100) + "文钱":"");
       
}
 
int check_pawn(object me)
{
        int i,value;
        string str,foo;
        mapping this_pawn;
        mapping *all_pawn;
     //   object me;
     //    me=this_player();
        all_pawn = me->query("pawn");
        if(!all_pawn ) return notify_fail("你目前没有典当任何物品。\n");
 
        str = "\n你目前典当的物品有：\n";
        for(i=0;i<sizeof(all_pawn);i++)
                {
                this_pawn = all_pawn[i];
                value = this_pawn["value"];
                foo = undefinedp(this_pawn["amount"])?"一":chinese_number(this_pawn["amount"]);
                foo += this_pawn["unit"] ;
                foo += this_pawn["name"] ;
                foo = sprintf("%-3d %-40s %-35s\n",i,foo,value_string(value));
                str += foo ;
                }
        me->start_more(str);
        return 1;
}
 
void pay_player(object who, int amount)
 
{
        object ob;
 
        if( amount < 1 ) amount = 1;
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}
 
int do_value(string arg)
{
        object ob;
        int value,amount;
 
        if( !arg || !(ob = present(arg, this_player())) )
                return notify_fail("你要拿什麽物品给当铺估价？\n");
 
        if( ob->query("money_id") )
                return notify_fail("这是「钱」，你没见过吗？\n");
 
        value = (amount = ob->query_amount())?amount*ob->query("base_value"):ob->query("value");
 
        if( value < 100  ) printf("%s一文不值。\n", ob->query("name"));
        else
          printf("%s价值%s。\n如果你要典当(pawn)，可以拿到%s及一张当票。\n" +
                "如果你要卖(sell)，可以拿到%s。\n",
ob->query("name"), value_string(value),value_string(value * 60 / 100), value_string(value * 80/100));

 
        return 1;
}
 
int do_pawn(string arg)
{
        string aload;
        object ob,me;
        int value,amount;
        mapping this_pawn;
        mapping *all_ob;
 
        if( !arg )
                {
                return check_pawn(this_player());
                }
        if( !(ob = present(arg, this_player())) )
                return notify_fail("你要典当什麽物品？\n");
 
        if( ob->query("money_id") )     return notify_fail("你要当「钱」？\n");
 
        value = (amount = ob->query_amount())?amount*ob->query("base_value"):ob->query("value");
        if( value < 80 ) return notify_fail("这样东西不值钱。\n");
        if(value >= 8000000 )
                return notify_fail("小店资金短缺，而您这东西太贵重了......\n");
 
        if( first_inventory(ob))
                return notify_fail("请先把"+ob->name()+"里面的东西取出来再当。\n");
         me = this_player();
         all_ob = me->query("pawn");

        if(!all_ob) all_ob = ({});
        if(sizeof(all_ob) >= MAX_PAWN_NUM )
                return notify_fail("你已经典当了太多东西了。\n");
 
        me->start_busy(2);
 
        this_pawn = ([ ]);
        this_pawn["file"] = base_name(ob);
        this_pawn["value"] = value;
        this_pawn["name"] = ob->name();
        if(amount) this_pawn["amount"] = amount;
        this_pawn["unit"] = amount?ob->query("base_unit"):ob->query("unit");
 
        if(aload = ob->query_autoload(1) )      this_pawn["load"] = aload;
 
        all_ob += ({this_pawn});
 
        message_vision("$N把身上的" + ob->name() + "拿出来典当了"
                + value_string(value * 60 / 100) + "。\n", me);
        me->set("pawn",all_ob);
 
        pay_player(me, value / 100 * 60);
        destruct(ob);
 
        return 1;
}
 
int do_sell(string arg)
{
        object ob;
        int value,amount;
 
        if( !arg || !(ob = present(arg, this_player())) )
                return notify_fail("你要卖断什麽物品？\n");
 
        if( ob->query("money_id") )     return notify_fail("你要卖「钱」？\n");
        value = (amount = ob->query_amount())?amount*ob->query("base_value"):ob->query("value");
        if( value < 10 ) return notify_fail("这样东西不值钱。\n");
 
 
        message_vision("$N把身上的" + ob->query("name") + "卖掉。\n",this_player());
 
        pay_player(this_player(), value / 100 * 80);
        ob->move(environment(this_player()));
        destruct(ob);
 
        return 1;
}
int do_redeem( string arg )
{
        object ob,me;
        int num,amount,value,afford;
        string file,err,aload,name;
        mapping this_pawn;
        mapping *all_pawn;
 
        me = this_player();
        notify_fail("你要取回什么物品？\n");
        if(!arg) return 0;
        if( !sscanf(arg, "%d" , num ) ) return 0;
        all_pawn = me->query("pawn");
        if((num<0)|| (num>=sizeof(all_pawn)) ) return 0;
 
        this_pawn = all_pawn[num];
        value = this_pawn["value"];
        //value = value/100;
 
        afford = me->can_afford(value);
        if(!afford ) return notify_fail("你不够钱耶。\n");
        if(afford == 2) return notify_fail("你不够零钱。\n");
 
        file = this_pawn["file"] ;
        me->pay_money(value);
 
        err = catch(ob = new(file));
        if( err || !ob ) {
                write("你觉得似乎失落了什麽重要的东西，最好通知一下巫师。\n");
                log_file("AUTOLOAD", sprintf("Fail to autoload %s of %s, error \n",
                        file, this_object()->query("name"), err));
                return 1;
                }
        me->start_busy(3);
        export_uid(ob);
        ob->move(me);
        if(aload = this_pawn["load"] ) ob->autoload(aload);
        if( (name = this_pawn["name"]) != ob->name() ) ob->set("name",name);
        if( amount = this_pawn["amount"] ) ob->set_amount(amount);
        all_pawn[num] = 0;
        all_pawn -= ({0});
        if(!sizeof(all_pawn))me->delete("pawn");
       
        else me->set("pawn",all_pawn);
 
        message_vision("$N赎回了"+ob->name()+"\n",me );
 
        return 1;
}
 

