// master.c

inherit NPC;

void create()
{
	set_name("���Ǻ���", ({ "master bonze", "master", "bonze" }) );

	set("gender", "����");
	set("age", 74);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("apprentice_available", 10);

	set("str", 17);
	set("int", 30);
	set("spi", 30);
	set("con", 30);

	set("atman", 2000);
	set("max_atman", 2000);

	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 5);

	set("mana", 600);
	set("max_mana", 600);

	set("combat_exp", 1000000);
	set("score", 9000);

	set_skill("unarmed", 80);
	set_skill("force", 100);
	set_skill("dodge", 30);
	set_skill("literate", 60);

	create_family("ɽ����", 26, "ס��");

	setup();
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say ������һ��һ������");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say ���ɽ����Ѿ�����ʮ�����ӣ���������ͽ�ˡ�");
	}
}

void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "����" )
		command("say �����ӷ�Ůʩ����Ҫ�����ɿ���Ц��");
	else if( (string)ob->query("class") != "bonze" )
		command("say �����ӷ�ʩ��Ը����ţ����ȵ�С����ȳ��ҡ�");
	else {
		command("say �����ӷ����գ����գ�");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		add("apprentice_availavble", -1);
		return 1;
	}
}
