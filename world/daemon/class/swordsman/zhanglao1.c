// master.c
// modified by thir in zh 97/7/10
#include <ansi.h>

inherit NPC;
//inherit F_MASTER;
//inherit F_QUEST;

void create()
{
	set_name("������", ({ "tang sanxing", "zhanglao", "tang" }) );
	set("nickname", "�����Ὥ");
	set("gender", "����" );
	set("class", "swordsman");
	set("age", 64);
	set("str", 27);
	set("per", 21);
	set("cor", 30);
	set("cps", 27);
	set("int", 24);

	set("max_force", 1700);
	set("force", 1700);
	set("force_factor", 4);

	set("rank_info/respect", "�Ƴ���");

	set("long",
		"��������Ŀǰ��ɽ���ɵ�ʮ������Ψһ�����������ˣ���Ϊ���г��ϡ�\n"
		"���뷢�Ѱף���������Ȼֱͦ��һ�ַ�ɽ����ʹ�ĳ����뻭��\n");

	create_family("��ɽ����", 12, "����");

	set("combat_exp", 2000000);
	set("score", 25000);

	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(: perform_action, "sword.counterattack" :)
	}) );

	set_skill("cuff", 50);
	set_skill("parry", 130);
	set_skill("dodge", 90);
	set_skill("sword", 130);
	set_skill("force", 60);
	set_skill("literate", 50);

	set_skill("fonxanforce", 80);
	set_skill("fonxansword", 130);
	set_skill("liuh-ken", 60);
	set_skill("chaos-steps", 120);
	set_skill("spider-array", 85);

        prepare_skill("cuff", "liuh-ken");
	map_skill("cuff", "liuh-ken");
	map_skill("sword", "fonxansword");
	map_skill("parry", "fonxansword");
	map_skill("dodge", "chaos-steps");

	set("inquiry", ([
//		"�������" : "����������ȸ�������������������������Ʒ�ɽ�Ż�����������������־��",
//		"������־" : "�ȸ�����֮ʱ������ݽ����������У���úú��տ���",
		"������" : "����ֶ�����Ƿ�ɽ���ɵ����Ű����ⶼ��֪����",
		"name": "�Ҿ��Ƿ�ɽ���ɵĳ��ϡ������Ὥ��������",
//		"here": "������Ǵ�����ݡ�",
	]) );

	setup();
	carry_object("/obj/weapon/gangjian")->wield();
	carry_object(__DIR__"hat")->wear();
	carry_object(__DIR__"silk_cloth")->wear();
	carry_object(__DIR__"boot")->wear();
}
/*
string quest_file(string tag) {
	return( "/quest/qlist0");
}


void init()
{
	::init();
        add_action("give_quest", "quest");
}
*/
// if not allow quest ,then return 0
//int valid_quest() {
//	return 1;
//}


