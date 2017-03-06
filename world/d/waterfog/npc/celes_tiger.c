// celes_tiger.c

inherit NPC;

void create()
{
	set_name("��а��", ({ "celestial tiger", "tiger" }) );
	set("long",
		"����һֻ��а�ɵ����ޡ���а����������ëƤ��������������\n"
		"���ƣ�տ��ɫ��������ɢ��������Ĺ�â��\n");

	set("race", "Ұ��");
	set("age", 160);
	set("attitude", "friendly");

	set("max_gin", 2000);
	set("max_kee", 3000);
	set("max_sen", 1000);

	set("str", 110);
	set("cor", 40);
	set("spi", 40);
	set("int", 60);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "����", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set_temp("apply/attack", 80);
	set_temp("apply/damage", 160);
	set_temp("apply/armor", 20);

	set("combat_exp", 1000000);
	set("score", 10000);
	setup();
}
