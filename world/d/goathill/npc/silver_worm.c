// silver_worm.c

inherit NPC;

void create()
{
	set_name("��ɫ����", ({ "silver rock leech", "leech" }) );
	set("long",
		"�������ο����������������������������δ���ͬ����ע�⵽��\n"
		"���а����о�΢΢�ط����⣬��֪�����������ʲô������\n");

	set("race", "Ұ��");
	set("unit", "��");
	set("age", 145);

	set("max_gin", 1500);
	set("max_kee", 1500);
	set("max_sen", 1500);

	set("str", 80);
	set("con", 80);
	set("cor", 80);
	set("cps", 80);
	set("spi", 20);
	set("int", 40);
	set("kar", 80);
	set("per", 10);

	set("limbs", ({ "ͷ��", "����" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 90);
	set_temp("apply/damage", 55);
	set_temp("apply/dodge", 90);
	set_temp("apply/armor", 160);
	set_temp("apply/armor_vs_force", 1000);

	set("combat_exp", 400000);
	setup();
}
