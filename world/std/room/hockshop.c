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
           return chinese_number(value) + "��Ǯ";
        else   
           return chinese_number(value/100) + "������"
           + (value%100? "��" + chinese_number(value%100) + "��Ǯ":"");
       
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
        if(!all_pawn ) return notify_fail("��Ŀǰû�е䵱�κ���Ʒ��\n");
 
        str = "\n��Ŀǰ�䵱����Ʒ�У�\n";
        for(i=0;i<sizeof(all_pawn);i++)
                {
                this_pawn = all_pawn[i];
                value = this_pawn["value"];
                foo = undefinedp(this_pawn["amount"])?"һ":chinese_number(this_pawn["amount"]);
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
                return notify_fail("��Ҫ��ʲ����Ʒ�����̹��ۣ�\n");
 
        if( ob->query("money_id") )
                return notify_fail("���ǡ�Ǯ������û������\n");
 
        value = (amount = ob->query_amount())?amount*ob->query("base_value"):ob->query("value");
 
        if( value < 100  ) printf("%sһ�Ĳ�ֵ��\n", ob->query("name"));
        else
          printf("%s��ֵ%s��\n�����Ҫ�䵱(pawn)�������õ�%s��һ�ŵ�Ʊ��\n" +
                "�����Ҫ��(sell)�������õ�%s��\n",
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
                return notify_fail("��Ҫ�䵱ʲ����Ʒ��\n");
 
        if( ob->query("money_id") )     return notify_fail("��Ҫ����Ǯ����\n");
 
        value = (amount = ob->query_amount())?amount*ob->query("base_value"):ob->query("value");
        if( value < 80 ) return notify_fail("����������ֵǮ��\n");
        if(value >= 8000000 )
                return notify_fail("С���ʽ��ȱ�������ⶫ��̫������......\n");
 
        if( first_inventory(ob))
                return notify_fail("���Ȱ�"+ob->name()+"����Ķ���ȡ�����ٵ���\n");
         me = this_player();
         all_ob = me->query("pawn");

        if(!all_ob) all_ob = ({});
        if(sizeof(all_ob) >= MAX_PAWN_NUM )
                return notify_fail("���Ѿ��䵱��̫�ණ���ˡ�\n");
 
        me->start_busy(2);
 
        this_pawn = ([ ]);
        this_pawn["file"] = base_name(ob);
        this_pawn["value"] = value;
        this_pawn["name"] = ob->name();
        if(amount) this_pawn["amount"] = amount;
        this_pawn["unit"] = amount?ob->query("base_unit"):ob->query("unit");
 
        if(aload = ob->query_autoload(1) )      this_pawn["load"] = aload;
 
        all_ob += ({this_pawn});
 
        message_vision("$N�����ϵ�" + ob->name() + "�ó����䵱��"
                + value_string(value * 60 / 100) + "��\n", me);
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
                return notify_fail("��Ҫ����ʲ����Ʒ��\n");
 
        if( ob->query("money_id") )     return notify_fail("��Ҫ����Ǯ����\n");
        value = (amount = ob->query_amount())?amount*ob->query("base_value"):ob->query("value");
        if( value < 10 ) return notify_fail("����������ֵǮ��\n");
 
 
        message_vision("$N�����ϵ�" + ob->query("name") + "������\n",this_player());
 
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
        notify_fail("��Ҫȡ��ʲô��Ʒ��\n");
        if(!arg) return 0;
        if( !sscanf(arg, "%d" , num ) ) return 0;
        all_pawn = me->query("pawn");
        if((num<0)|| (num>=sizeof(all_pawn)) ) return 0;
 
        this_pawn = all_pawn[num];
        value = this_pawn["value"];
        //value = value/100;
 
        afford = me->can_afford(value);
        if(!afford ) return notify_fail("�㲻��ǮҮ��\n");
        if(afford == 2) return notify_fail("�㲻����Ǯ��\n");
 
        file = this_pawn["file"] ;
        me->pay_money(value);
 
        err = catch(ob = new(file));
        if( err || !ob ) {
                write("������ƺ�ʧ����ʲ����Ҫ�Ķ��������֪ͨһ����ʦ��\n");
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
 
        message_vision("$N�����"+ob->name()+"\n",me );
 
        return 1;
}
 

