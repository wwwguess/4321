inherit NPC;

void create()
{
	set_name("֩��", ({ "spider" }) );
	set("race", "Ұ��");
	set("age", 1);
	set("long",@LONG
����һֻ�����൱���֩��, �����е�����.

LONG
	);
	set("str", 20);

	set("limbs", ({ "ͷ��", "����" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 15);
	set_temp("apply/armor",5);
	set_temp("apply/dodge",10);

	setup();
}
