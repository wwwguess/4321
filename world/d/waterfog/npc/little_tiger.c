// little_tiger.c

inherit NPC;

void create()
{
	set_name("С��а��", ({ "little tiger", "tiger" }) );
	set("long",
		"����һֻ��а�ɵ����ޡ���а����������ëƤ��������������\n"
		"���ƣ�Ȼ����ֻ��а���������Ȼ����С��˵�������������ꡣ\n");

	set("race", "Ұ��");
	set("age", 1);
	set("attitude", "friendly");

	set("max_gin", 300);
	set("max_kee", 300);
	set("max_sen", 100);

	set("str", 26);
	set("con", 36);
	set("cor", 20);
	set("spi", 30);
	set("int", 60);
	set("cps", 25);
	set("per", 60);
	set("kar", 70);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "����", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 10);

	set("combat_exp", 2000);
	setup();
}
