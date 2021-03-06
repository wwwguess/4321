// rat.c
//by dwolf
#include <ansi.h>

inherit NPC;

void create()
{
	set_name(RED"大老鼠"NOR, ({ "rat", "lao shu" }) );
	set("race", "野兽");
	set("age", 3);
	set("long", YEL"一只大得吓人的老鼠，看着你来，一点也不怕。\n"NOR);
	set("attitude", "peaceful");
	
	set("str", 15);
	set("cor", 30);

	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 500);
	set("shen_type", -1);
        set("chat_chance", 6);
	set("chat_msg", ({
                "大老鼠叫个不停：吱！吱！吱！吱！----\n",
	}) );
		
	set_temp("apply/attack", 10);
	set_temp("apply/damage", 4);
	set_temp("apply/armor", 2);

	setup();
}

void die()
{
	object ob;
	message_vision("$N惨嚎一声，死了！\n", this_object());
	ob = new(__DIR__"obj/shurou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
