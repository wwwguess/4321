// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("教授", ({ "jiao shou" , "jiao" , "shou" }));
	set("title",YEL"国子监教授"NOR);
	set("long",
	"国子监的教授，他精通文磨，对诗词歌赋都有一定的研究,得空来国子监给学生们讲讲课。\n");
	set("gender", "男性");
	set("age", 55);
	set("attitude", "peaceful");
	set("str", 15);
	set("int", 15);
	set("con", 15);
	set("dex", 15);
	set("combat_exp", 4000);
	set_skill("dodge", 10);
	set_skill("unarmed", 20);
	set_temp("apply/defense", 10);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"教授看着手里的文章，拍岸叫好道：真是妙不可言啊！\n",	
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
//	command("say "+RANK_D->query_respect(me)+"你可有兴趣来这儿读书作画？\n");
