// master.c

inherit NPC;

void create()
{
	set_name("��ֹƼ", ({ "master dancer", "master", "dancer" }) );

	set("title", "����ׯ��");
	set("nickname", "��������");
	set("gender", "Ů��");
	set("age", 22);
	set("long",
		"��ֹƼ��һ��ʮ�ֳ�ɫ����Ů��������һ����\�ø�������ǧ���\��\n"
		"�����ӵܣ����̺��Ͷ�Ϊ��������˫����ò�������㵹��\n");
	set("attitude", "peaceful");
	set("class", "dancer");
	set("apprentice_available", 10);

	set("str", 21);
	set("int", 28);
	set("spi", 26);
	set("per", 30);

	set("force", 600);
	set("max_force", 600);

	set("combat_exp", 1000000);
	set("score", 9000);

	set_skill("unarmed", 40);
	set_skill("sword", 70);
	set_skill("throwing", 100);
	set_skill("force", 30);
	set_skill("parry", 70);
	set_skill("dodge", 100);
	set_skill("literate", 100);
	set_skill("perception", 100);

	create_family("����ׯ", 1, "ׯ��");

	setup();

	carry_object(__DIR__"echowhip")->wield();
	carry_object(__DIR__"snake_sandal")->wear();
	carry_object(__DIR__"gold_belt")->wear();
	carry_object(__DIR__"bloody_dress")->wear();
}

void reset()
{
	delete_temp("learned");
	set("apprentice_available", 10);
}

int prevent_learn(object me, string skill)
{
	if( (int)query_temp("learned/" + me->query("id")) > 15 ) {
		command("say ��˵" + me->name(1) + "������Ҫ���Ǵ���ʦ����ߣ���ȥĥ��ĥ���ɡ�\n");
		return 1;
	} else
		add_temp("learned/" + me->query("id"), 1);
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say ������һ��һ������");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say ��ׯ�������Ѿ�����ʮ�����ӣ���������ͽ�ˡ�");
	}
}

void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "Ů��" )
		command("say ���˶����Ǻö�����������");
	else {
		command("say �ܺã�ֻҪ��Ա�ׯ�����Ĺ������ô����ٲ��˵ġ�");
		if( (int)ob->query("per") > 25 && (int)ob->query("age") < 20 )
			message_vision("$N�����ظ�����$n������˵�����ر�������������Ů��....\n", this_object(), ob);
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "dancer");
	add("apprentice_availavble", -1);
}
