// taolord.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�ּ�", ({ "master taolord", "master", "taolord" }) );
	set("nickname", "��ָ����");
	set("gender", "����");
	set("age", 47);
	set("long",
		"�ּ���һλ����ʮ�ָ�����޵��ߣ��㷢����������һ���Ǻ�ɫ�ģ�һ\n"
		"���ǽ�ɫ�ģ������ǡ���\���ķ������������߾�������ס�\n");

	set("combat_exp", 1000000);
	set("score", 200000);

	set("class", "taoist");

	set("str", 20);
	set("int", 30);
	set("cor", 20);
	set("cps", 30);
	set("spi", 30);

	set("force", 700);
	set("max_force", 700);
	set("force_factor", 3);

	set("atman", 1400);
	set("max_atman", 1400);

	set("mana", 2000);
	set("max_mana", 2000);
	set("mana_factor", 5);

	set("inquiry", ([
		"��\���ķ�": "��\���ķ�����éɽ��Ϊ�Կ�аħ����������ڹ�\�ķ���\n",
		"éɽ��": "��éɽ��������ʦ��ɽ�������������������Խ�����ħΪ���Ρ�\n"
	]) );

	set("apprentice_available", 3);
	set("chat_chance", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "drainerbolt" :),
		(: cast_spell, "netherbolt" :),
		(: cast_spell, "feeblebolt" :),
		(: cast_spell, "invocation" :),
	}) );

	create_family("éɽ��", 5, "��ʦ");

	set_skill("literate", 70);
	set_skill("magic", 80);
	set_skill("force", 30);
	set_skill("spells", 100);
	set_skill("scratching", 100);
	set_skill("unarmed", 30);
	set_skill("sword", 40);
	set_skill("parry", 40);
	set_skill("dodge", 40);
	set_skill("gouyee", 60);

	set_skill("taoism", 100);
	set_skill("necromancy", 100);

	map_skill("magic", "taoism");
	map_skill("spells", "necromancy");

	set_temp("apply/dodge", 20);
	set_temp("apply/armor", 20);

	setup();

	carry_object(__DIR__"sword")->wield();
	carry_object(__DIR__"robe")->wear();
	carry_object(__DIR__"hat")->wear();
	carry_object(__DIR__"shoe")->wear();
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say ������һ��һ������");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say ƶ�������Ѿ������������ӣ���������ͽ�ˡ�");
	}
}

void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "����" )
		command("say ƶ���ǳ����ˣ�������Ůͽ�������ˡ�");
	else {
		command("say ��... ������éɽ�ɣ�Ҳ��....");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "taoist");
	add("apprentice_availavble", -1);
}

