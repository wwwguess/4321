// banker.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
        set_name("²·Ó¥", ({ "ying" }) );
        set("title", "Ó¥¼ÇÀÏ°å");
        set("gender", "ÄÐÐÔ" );
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
"²·Ó¥ÊÇ¸ö¿´ÆðÀ´Ïàµ±Ó¢¿¡µÄÄêÇáÈË£¬²»¹ýµãÉñÃØÄª²âµÄ¸Ð¾õ¡£\n"
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
        command("say ß×... Òª´ò¾ÍÕæ´ò°É£¬¹âÊÇ½ÏÁ¿¶àÃ»ÒâË¼£¿");
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
                return notify_fail("Ö¸Áî¸ñÊ½£ºconvert <ÊýÁ¿> <»õ±ÒÖÖÀà> to <»õ±Ò
ÖÖÀà>\n");

        from_ob = present(from + "_money", this_player());
        to_ob = present(to + "_money", this_player());
       if (this_player()->is_busy()) return notify_fail("±ð¼±£¬ÂýÂýÀ´£¬Ç®ÒªµãÇ
å³þ£¡£¡\n");
        if( !to_ob && file_size("/obj/money/" + to + ".c") < 0 )
                return notify_fail("ÄãÏë¶Ò»»ÄÄÒ»ÖÖÇ®£¿\n");

        if( !from_ob )          return notify_fail("ÄãÉíÉÏÃ»ÓÐÕâÖÖ»õ±Ò¡£\n");
        if( amount < 1 )        return notify_fail("¶Ò»»»õ±ÒÒ»´ÎÖÁÉÙÒª¶Ò»»Ò»¸ö¡£
\n");

        if( (int)from_ob->query_amount() < amount )
                return notify_fail("ÄãÉíÉÏÃ»ÓÐÄÇ÷á¶à" + from_ob->query("name") +
 "¡£\n");

        bv1 = from_ob->query("base_value");
        if( !bv1 ) return notify_fail("ÕâÖÖ¶«Î÷²»ÖµÇ®¡£\n");

        bv2 = to_ob ? to_ob->query("base_value") : call_other("/obj/money/" + to
, "query", "base_value" );

        if( bv1 < bv2 ) amount -= amount % (bv2 / bv1);
        if( amount==0 ) return notify_fail("ÕâÐ©" + from_ob->query("name") + "µÄ
¼ÛÖµÌ«µÍÁË£¬»»²»Æð¡£\n");          
        if( !to_ob ) {
                to_ob = new("/obj/money/" + to);
                to_ob->move(this_player());
                to_ob->set_amount(amount * bv1 / bv2);
        } else
                to_ob->add_amount(amount * bv1 / bv2);
/*	message_vision(sprintf("$N´ÓÉíÉÏÈ¡³ö%s%s%s,»»³É%s%s%s¡£ \n",amount,
from_ob->query("base_unit"),
from_ob->quesry("name"),amount*bv1/bv2,to_ob->query("base_unit"),to_ob->query("name")),
this_player() );
*/
        message_vision( sprintf("$N´ÓÉíÉÏÈ¡³ö%s%s%s£¬»»³É%s%s%s¡£\n",
chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), 
to_ob->query("name")),
                this_player() );

        from_ob->add_amount(-amount);

        return 1;
}
