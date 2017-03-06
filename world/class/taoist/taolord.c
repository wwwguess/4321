// taolord.c

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

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

	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 30);

	set("atman", 1400);
	set("max_atman", 1400);

	set("mana", 4000);
	set("max_mana", 2000);
	set("mana_factor", 5);

	set("inquiry", ([
		"�����ķ�": "�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
		"éɽ��": "��éɽ��������ʦ��ɽ�������������������Խ�����ħΪ���Ρ�\n"
	]) );

	set("apprentice_available", 3);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "drainerbolt" :),
		(: cast_spell, "netherbolt" :),
		(: cast_spell, "feeblebolt" :),
		(: cast_spell, "invocation" :),
	}) );

	create_family("éɽ��", 5, "��ʦ");

	set_skill("literate", 90);
	set_skill("magic", 60);
	set_skill("force", 60);
	set_skill("spells", 150);
	set_skill("cuff", 70);
	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);

	set_skill("gouyee", 80);
	set_skill("taosword", 80);
	set_skill("taoism", 100);
	set_skill("necromancy", 150);

	map_skill("spells", "necromancy");
	map_skill("sword", "taosword");

	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);

	setup();

	carry_object(__DIR__"sword")->wield();
	carry_object(__DIR__"robe")->wear();
	carry_object(__DIR__"hat")->wear();
	carry_object(__DIR__"shoe")->wear();
}

void init() {
	::init();
	add_action("give_quest","quest");

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

// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"��$Nһ˦���䣬˵���� ʲô�������¸���𣿣�\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"��$Nһ˦���䣬˵���� �汿����ú�ѧѧ������Ҫ����ɣ�\n" ,who);
    who->set("quest",0);
    return(0);
}

