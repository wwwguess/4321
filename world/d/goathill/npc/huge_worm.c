// huge_worm.c

inherit NPC;

void create()
{
	set_name("������", ({ "huge rock leech", "leech" }) );
	set("long",
		"һ��ɫ��ǳ�ң�������ɫ�ߵ��ˮ��ģ���ֳ棬����¶�����԰�ɭɭ\n"
		"�����ݣ����������ļ��ˡ�\n");

	set("race", "Ұ��");
	set("unit", "��");
	set("age", 8);

	set("max_gin", 400);
	set("max_kee", 900);
	set("max_sen", 400);

	set("str", 80);
	set("con", 40);
	set("cor", 80);
	set("cps", 5);
	set("spi", 1);
	set("int", 1);
	set("kar", 5);
	set("per", 0);

	set("limbs", ({ "ͷ��", "����" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 60);
	set_temp("apply/damage", 35);
	set_temp("apply/dodge", 30);
	set_temp("apply/armor", 80);

	set("combat_exp", 10000);
	setup();
}
