// tiger.c 
//by dwolf

#include <ansi.h>  
inherit NPC;

void create()
{
	set_name(YEL"�ϻ�"NOR, ({ "tiger" }) );
	set("race", "Ұ��");
	set("age", 14);
	set("long", "һͷ���͵İ�쵴󻢣�һ˫�۾�����ֵص����㡣\n");
	set("attitude", "aggressive");
	
	set("str", 150);
	set("cor", 150);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 200000);

	set_temp("apply/attack", 75);
	set_temp("apply/damage", 76);
	set_temp("apply/armor", 100);

	setup();
}
