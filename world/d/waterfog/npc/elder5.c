// elder5.c

inherit NPC;

void create()
{
	set_name("��Σˮ", ({ "nan weishuey", "nan", "weishuey" }) );
	set("title", "ˮ�̸��峤��");
	set("gender", "����");
	set("age", 52);
	set("long",
		"��Σˮ�ǵ���ʹ�������ң�Ҳ�ǻ������ĵܵܣ�һ����ѧ����а����ɽ\n"
		"����֮��������ˮ�̸��߳������书\�����ڶ�����Īǫ�ݡ���Σˮ����\n"
		"�Ľ��佣Ҳ��һ�Ѻ�������������˵��ѽ���������ʦ��������ƽ����\n"
		"������������һ�Ľ�����\n");

	set("attitude", "peaceful");
	set("combat_exp", 1200000);
	set("score", 20000);

	set("str", 25);
	set("cor", 30);
	set("cps", 30);
	set("con", 27);

	set("force", 1600);
	set("max_force", 1600);
	set("force_factor", 3);

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.counterattack" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set_skill("force", 110);
	set_skill("unarmed", 95);
	set_skill("sword", 110);
	set_skill("parry", 100);
	set_skill("dodge", 105);

	set_skill("celestial", 100);
	set_skill("celestrike", 90);
	set_skill("fonxansword", 110);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("sword", "fonxansword");
	map_skill("parry", "fonxansword");

	setup();

	carry_object(__DIR__"obj/sorrowfire")->wield();
	carry_object("/obj/cloth")->wear();
	add_money("silver", 30);
}
