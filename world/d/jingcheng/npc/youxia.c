// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("游侠儿", ({ "you xiaer", "youxia" }));
	set("title",GRN"风流倜傥"NOR);
	set("long",
	"时下游侠之风甚重，连长安街头也可看到华装佩剑少年。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "heroism");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("per", 30);
	set("combat_exp", 30000+random(5000));
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("sword", 70);
	set_temp("apply/defense", 20);
	set_temp("apply/attack", 20);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		(: random_move :),
        	"游侠儿曼声吟道：仗剑江湖，游戏人间，这是何等快活逍遥之事。\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/gangjian")->wield();
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
void greeting(object me)
{
	object obj;

	command("say "+RANK_D->query_respect(me)+"跟我一起闯荡江湖吧。\n");
	command("smile");
	if( random(10) > 7 )
	{
		command("l "+me->query("id"));
		message_vision("游侠儿对$N说道：“"+RANK_D->query_close(me)+
		"看来武艺高强，可否与我比划比划。\n",me);
		command("fight "+me->query("id"));
		return;
	} 
	switch( random(3) ){
		case 0:
			if( present(me->query("id"), environment(me)) ){
				command("pat "+(string)me->query("id"));
				if( me->query("gender") == "女性" )
				command("kiss "+me->query("id"));
			}
			break;	
		case 1:			
			command("haha");
			message_vision("游侠儿拔出长剑，舞了两个剑花，笑道:你看，漂亮吗？\n");	
			break;
		default:
			if( present(me->query("id"), environment(me)) ){
				command("hi "+(string)me->query("id"));
				message_vision("游侠儿大笑：“我欲乘风归去，仙人抚我顶，结发共长生。\n");
				command("bye "+(string)me->query("id"));
				obj = new(__DIR__"obj/yuanbao");
				message_vision("游侠儿拉着$N的手，塞给$N一锭元宝。\n",me);
				obj->move(me);
				break;
			}
	}
	return;
}
