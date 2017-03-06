// master.c

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
void consider();

void create()
{
	set_name("������", ({ "master scholar", "master", "scholar" }) );

	set("gender", "����");
	set("age", 32);
	set("long",
		"��������춾����������������ң����ı������潨�ף�������Ϊ����ϲ��\n"
		"�Ĵ��ε������Ժš����ۡ����Ĵ���ɽ��ˮ���ύ�������ˡ�����ǰ�̳�\n"
		"�丸���׶���Ϊ�����ɵ��������ţ�����ϲ��Ʈ���ĸ�����Ȼ���ģ�����\n"
		"������ͷʹ���ѡ�\n" );

	set("class", "scholar");
	set("attitude", "peaceful");
	create_family("������", 7, "������");

	set("str", 26);
	set("cor", 30);
	set("int", 30);
	set("cps", 30);
	set("con", 25);
	set("spi", 30);
	set("per", 22);
	set("kar", 24);

	set("force", 3000);
	set("max_force", 1600);
	set("force_factor", 20);

	set("combat_exp", 1000000);
	set("score", 200000);

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: perform_action, "move.hasten" :),
	}) );

	set_skill("finger", 60);
	set_skill("sword", 100);
	set_skill("force", 80);
	set_skill("parry", 60);
	set_skill("dodge", 100);
	set_skill("move", 100);
	set_skill("literate", 150);
	set_skill("perception", 80);
	set_skill("music", 100);
	set_skill("instruments", 70);

	set_skill("mystforce", 100);
	set_skill("mysterrier", 100);
	set_skill("mystsword", 100);

	map_skill("force", "mystforce");
	map_skill("dodge", "mysterrier");
	map_skill("move", "mysterrier");
	map_skill("sword", "mystsword");

	set("shen_type",1);
	setup();

	carry_object(__DIR__"windspring")->wield();
	carry_object("/obj/cloth")->wear();
}

int accept_learn(object me, string skill)
{
	if( (int)me->query_skill(skill, 1) > (int)me->query_skill("literate", 1) )
	{
		tell_object(me,"�����۶���ר����ѧ�ƺ���̫���⣬����ö໨һЩ�����ڶ����ϡ�\n");
		return notify_fail("�����۶���ר����ѧ�ƺ���̫���⣬����ö໨һЩ�����ڶ����ϡ�\n");
	}
	return ::accept_learn(me, skill);
}

void attempt_apprentice(object me)
{
	command("hmm");
	command("say " + RANK_D->query_respect(me) + "���ĳ�Ϊ�Ҳ����ɵĵ��ӣ����ٺò����ˡ�\n");
	command("recruit " + me->query("id"));
}

int recruit_apprentice(object ob)
{
	ob->set("class", "scholar");
	return ::recruit_apprentice(ob);
}

void init()
{
   add_action("give_quest","quest");
}

/*void init()
{
	::init();
        add_action("give_quest", "quest");
}
*/
// if not allow quest ,then return 0
//int valid_quest() {
//	return 1;
//}


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

