// rat.c
//by dwolf
#include <ansi.h>

inherit NPC;

void create()
{
	set_name(RED"������"NOR, ({ "rat", "lao shu" }) );
	set("race", "Ұ��");
	set("age", 3);
	set("long", YEL"һֻ������˵����󣬿���������һ��Ҳ���¡�\n"NOR);
	set("attitude", "peaceful");
	
	set("str", 15);
	set("cor", 30);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 500);
	set("shen_type", -1);
        set("chat_chance", 6);
	set("chat_msg", ({
                "������и���ͣ��֨��֨��֨��֨��----\n",
	}) );
		
	set_temp("apply/attack", 10);
	set_temp("apply/damage", 4);
	set_temp("apply/armor", 2);

	setup();
}

void die()
{
	object ob;
	message_vision("$N�Һ�һ�������ˣ�\n", this_object());
	ob = new(__DIR__"obj/shurou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
