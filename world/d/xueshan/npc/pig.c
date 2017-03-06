//by dwolf
// pig.c 

#include <ansi.h>  
inherit NPC;

void create()
{
	set_name(RED"Ұ��"NOR, ({ "pig" }) );
	set("race", "Ұ��");
	set("age", 24);
	set("long", "һͷ�׶��Ұ��\n");
	set("attitude", "aggressive");
	
	set("str", 80);
	set("cor", 50);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 100000);

	set_temp("apply/attack", 35);
	set_temp("apply/damage", 36);
	set_temp("apply/armor", 50);

	setup();
}
