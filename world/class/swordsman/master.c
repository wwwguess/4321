// master.c
// modified by thir in zh 97/7/10
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
	set_name("������", ({ "master swordsman", "swordsman", "master" }) );
	set("nickname", "����˫��");
	set("gender", "����" );
	set("class", "swordsman");
	set("age", 44);
	set("str", 27);
	set("cor", 30);
	set("cps", 27);
	set("int", 24);

	set("max_force", 1500);
	set("force", 1500);
	set("force_factor", 3);

	set("rank_info/respect", "������");

	set("long",
		"�������Ǹ��൱�ߴ�����������������Ǵ�����������ġ����ս�����\n"
		"��Ų²�����ǰ����������ŵ������˾��ǼҴ���ݵĹ�����\n");

	create_family("��ɽ����", 13, "������");

	set("combat_exp", 1000000);
	set("score", 200000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.counterattack" :)
	}) );

	set_skill("cuff", 40);
	set_skill("parry", 100);
	set_skill("dodge", 80);
	set_skill("sword", 120);
	set_skill("force", 40);
	set_skill("literate", 60);

	set_skill("fonxanforce", 60);
	set_skill("fonxansword", 120);
	set_skill("liuh-ken", 60);
	set_skill("chaos-steps", 100);
	set_skill("spider-array", 85);

        prepare_skill("cuff", "liuh-ken");
	map_skill("cuff", "liuh-ken");
	map_skill("sword", "fonxansword");
	map_skill("parry", "fonxansword");
	map_skill("dodge", "chaos-steps");

	set("inquiry", ([
		"�������" : "����������ȸ�������������������������Ʒ�ɽ�Ż�����������������־��",
		"������־" : "�ȸ�����֮ʱ������ݽ����������У���úú��տ���",
		"����»" : "���ֵ��ں�������Ѿ������ˣ���ȥ֮�²������ᡣ",
		"name": "���Ȼ֪�����������������᲻֪�����������磿",
		"here": "������Ǵ�����ݡ�",
	]) );

	setup();
	carry_object(__DIR__"blackthorn")->wield();
	carry_object(__DIR__"hat")->wear();
	carry_object(__DIR__"silk_cloth")->wear();
	carry_object(__DIR__"boot")->wear();
}
/*
string quest_file(string tag) {
	return( "/quest/qlist0");
}
*/

void init()
{
	::init();
        add_action("give_quest", "quest");
}

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

void attempt_apprentice(object ob)
{
	if( ((int)ob->query("cor") < 20) 
	||	((int)ob->query("cps") < 20)) {
		command("say ѧ��֮�˱��뵨����ϸ�����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ˣ�");
		return;
	}
	command("smile");
	command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�\n");
	command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "swordsman");
}
