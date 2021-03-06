// banker.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
        set_name("卜鹰", ({ "ying" }) );
        set("title", "鹰记老板");
        set("gender", "男性" );
        set("age", 26);

        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 53);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);

        set("long",
"卜鹰是个看起来相当英俊的年轻人，不过点神秘莫测的感觉。\n"
                );

        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("env/wimpy", 70);

        set("max_atman", 1000);         set("atman", 1000);             
set("atman_factor", 3);
        set("max_force", 1000);         set("force", 1000);             
set("force_factor", 3);
        set("max_mana", 1000);          set("mana", 1000);              
set("mana_factor", 3);

        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("shortsong-blade", 100);
        set_skill("fall-steps", 100);
        set_skill("bolomiduo", 100);
	set_skill("blade", 200);
        map_skill("force", "bolomiduo");
        map_skill("dodge", "fall-steps");
	map_skill("parry", "shortsong-blade");
        map_skill("blade", "shortsong-blade");
        
        setup();
        
        carry_object(__DIR__"obj/roundblade")->wield();
        carry_object("/obj/cloth")->wear();

        add_money("gold", 10);
}

int accept_fight(object me)
{
        command("say 咦... 要打就真打吧，光是较量多没意思？");
        command("grin");
        kill_ob(me);
        return 1;
}
void init()
{
        add_action("do_convert", "convert");
//        add_action("do_deposit", "deposit");
}

int do_convert(string arg)
{
        string from, to;
        int amount, bv1, bv2;
        object from_ob, to_ob;

        if( !arg || sscanf(arg, "%d %s to %s", amount, from, to)!=3 )
                return notify_fail("指令格式：convert <数量> <货币种类> to <货币
种类>\n");

        from_ob = present(from + "_money", this_player());
        to_ob = present(to + "_money", this_player());
       if (this_player()->is_busy()) return notify_fail("别急，慢慢来，钱要点�
宄。n");
        if( !to_ob && file_size("/obj/money/" + to + ".c") < 0 )
                return notify_fail("你想兑换哪一种钱？\n");

        if( !from_ob )          return notify_fail("你身上没有这种货币。\n");
        if( amount < 1 )        return notify_fail("兑换货币一次至少要兑换一个。
\n");

        if( (int)from_ob->query_amount() < amount )
                return notify_fail("你身上没有那麽多" + from_ob->query("name") +
 "。\n");

        bv1 = from_ob->query("base_value");
        if( !bv1 ) return notify_fail("这种东西不值钱。\n");

        bv2 = to_ob ? to_ob->query("base_value") : call_other("/obj/money/" + to
, "query", "base_value" );

        if( bv1 < bv2 ) amount -= amount % (bv2 / bv1);
        if( amount==0 ) return notify_fail("这些" + from_ob->query("name") + "的
价值太低了，换不起。\n");          
        if( !to_ob ) {
                to_ob = new("/obj/money/" + to);
                to_ob->move(this_player());
                to_ob->set_amount(amount * bv1 / bv2);
        } else
                to_ob->add_amount(amount * bv1 / bv2);
/*	message_vision(sprintf("$N从身上取出%s%s%s,换成%s%s%s。 \n",amount,
from_ob->query("base_unit"),
from_ob->quesry("name"),amount*bv1/bv2,to_ob->query("base_unit"),to_ob->query("name")),
this_player() );
*/
        message_vision( sprintf("$N从身上取出%s%s%s，换成%s%s%s。\n",
chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), 
to_ob->query("name")),
                this_player() );

        from_ob->add_amount(-amount);

        return 1;
}
