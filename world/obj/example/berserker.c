// berserker.c

inherit NPC;

void create()
{
	set_name("ç�Ծ������սʿ", ({ "giant berserker", "giant", "berserker" }) );
	set("long",
		"ç�Ծ�����Ŀ�սʿ����վ��������ǰͻȻ�е��Լ�����С��\n");

	set("race", "����");
	set("age", 84);

	set("max_gin", 2500);
	set("max_kee", 4000);
	set("max_sen", 1100);

	set("max_force", 500);
	set("force", 500);
	set("force_factor", 3);

	set("str", 90);
	set("cor", 60);
	set("spi", 10);
	set("int", 10);

	set_temp("apply/attack", 30);
	set_temp("apply/damage", 40);
	set_temp("apply/dodge", -10);
	set_temp("apply/armor", 40);

	set("combat_exp", 180000);
	set("bellicosity", 40000);

	set_skill("axe", 70);
	set_skill("dodge", 80);
	set_skill("parry", 60);

	setup();
	carry_object(__DIR__"bastard_axe")->wield();
}
