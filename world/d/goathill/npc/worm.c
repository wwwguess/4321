// worm.c

inherit NPC;

void create()
{
	set_name("����", ({ "rock leech", "leech" }) );
	set("long",
		"һ��ɫ��ǳ�ң�������ɫ�ߵ��ˮ��ģ���ֳ棬����¶�����԰�ɭɭ\n"
		"�����ݣ����������ļ��ˡ�\n");

	set("race", "Ұ��");
	set("unit", "��");
	set("age", 5);

	set("max_gin", 200);
	set("max_kee", 200);
	set("max_sen", 200);

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

	set_temp("apply/attack", 30);
	set_temp("apply/damage", 20);
	set_temp("apply/dodge", 20);
	set_temp("apply/armor", 30);

	set("combat_exp", 1000);
	set("corpse_ob", __DIR__"obj/dead_leech");
	setup();
}
