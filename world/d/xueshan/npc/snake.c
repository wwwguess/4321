// snake.c
//by dwolf 

#include <ansi.h>   
inherit NPC;

void create()
{
	set_name(MAG"����"NOR, ({ "snake" }) );
	set("race", "Ұ��");
	set("age", 14);
	set("long", "һ����ˮͰ�Ĵ����ߡ�\n");
	set("attitude", "aggressive");
	
	set("str", 90);
	set("cor", 100);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 150000);

	set_temp("apply/attack", 35);
	set_temp("apply/damage", 36);
	set_temp("apply/armor", 50);

	setup();
}
