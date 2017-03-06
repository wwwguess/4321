// guard.c

inherit NPC;

void create()
{
	set_name("ˮ�̸������ʿ", ({ "waterfog elite guard", "guard" }) );
	set("gender", "����");
	set("age", 38);
	set("long", "�����������ɫˮ�̸���ʿ��ɫ������ʮ��������\n");

	set("attitude", "peaceful");
	set("combat_exp", 100000);
	set("score", 8000);

	set("str", 28);
	set("cor", 27);
	set("cps", 27);
	set("con", 27);

	set("force", 1800);
	set("max_force", 1000);
	set("force_factor", 40);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		"������ʿ�ȵ�����������Ҳ����ˮ�̸���Ұ�����ǲ���������\n",
		"������ʿ˵����������ɽȥ����������������\n",
	}) );

	set_skill("force", 80);
	set_skill("unarmed", 90);
	set_skill("parry", 80);
	set_skill("dodge", 80);

	set_skill("celestial", 80);
	set_skill("celestrike", 80);
	set_skill("pyrobat-steps", 80);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("dodge", "pyrobat-steps");

	setup();

	carry_object(__DIR__"obj/guard_suit")->wear();
	carry_object(__DIR__"obj/red_suit")->wear();
	carry_object(__DIR__"obj/red_hat")->wear();
	carry_object(__DIR__"obj/leather_boot")->wear();
}

int accept_fight(object me)
{
	command("say ��λ" + RANK_D->query_respect(me) + "����������ִ������ˡ�����㡣");
	return 0;
}

void accept_kill(object me)
{
	command("say �� ... ԭ�����������鷳������");
	exert_function("powerup");
}

void return_home(object home)
{
	::return_home(home);
	command("guard " + environment()->query("waterfog_guard_dir"));
}
