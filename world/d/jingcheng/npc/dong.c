// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;
void create()
{
	set_name("董朴生", ({ "dong pusheng" , "dong" , "pusheng" }));
	set("title","当铺掌柜");
	set("nickname", HIW"一毛不拔"NOR); 
	set("long",
	"董家世代都是长安城里的望族，传到董朴生这一代，董家家大业大，在加上董朴生为人精明，\n"
	"更是发扬光大。董朴生外号「一毛不拔」，生性吝啬，但是做生意却是行家里手。\n");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("per", 15);
	set("force", 50);
	set("max_force", 50);
	set("force_factor", 2);
	set("combat_exp", random(100000));
	set_skill("dodge", 30);
	set_skill("unarmed", 40);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"董朴生热情的招呼你道：“客人尽管放心，本店价格公道，童叟无欺。”\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
//       add_action("do_vendor_list","list");
//       add_action("do_buy","buy");
//       add_action("do_sell","sell");
//       add_action("do_value","value");
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	command("say "+RANK_D->query_respect(me)+"随便转转，看看有什么中意的。\n");
	command("whisper "+(string)me->query("id")+" 本店代卖物品。"+RANK_D->query_respect(me)
	+"如果有什么不方便卖的东西，可以交给本店。老字号了，尽管放心。\n");
}
