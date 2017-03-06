// watcher.c

inherit NPC;

void create()
{
	set_name("��Υ", ({ "yen wei", "yen", "wei" }) );
	set("title", "ˮ�̸��߳���");
	set("gender", "����");
	set("age", 53);
	set("long",
		"��Υ��ˮ�̸���λ������������ģ���Ȼ�����书\��������λ����\n"
		"�������ѷһ�����������ʮ�־�������������߳���ÿ�궼��\n"
		"������������ִ�����ˡ�\n");

	set("attitude", "peaceful");
	set("combat_exp", 700000);
	set("score", 6000);

	set("str", 25);
	set("cor", 23);
	set("cps", 23);
	set("con", 27);

	set("force", 1300);
	set("max_force", 1300);
	set("force_factor", 5);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set_skill("force", 100);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("dodge", 75);

	set_skill("celestial", 90);
	set_skill("celestrike", 80);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");

	setup();
}
