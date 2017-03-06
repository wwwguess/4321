// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("酸秀才", ({ "suan xiucai" , "suan" , "xiucai" }));
	set("title",CYN"国子监贡生"NOR);
	set("long",
	"国子监的秀才，专好吟诗作画，附庸风雅之事。\n");
	set("gender", "男性");
	set("age", 22);
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 2000);
	set_skill("dodge", 10);
	set_skill("unarmed", 20);
	set_temp("apply/defense", 5);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"酸秀才摇头晃脑的吟道：“床前明月无光，疑是地上有霜。”\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
//void greeting(object me)
//{
//	command("say "+RANK_D->query_respect(me)+"你看我这诗写得可好？\n");
