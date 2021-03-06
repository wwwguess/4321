// master.c
// modified by thir in zh 97/7/10
#include <ansi.h>

inherit NPC;
//inherit F_MASTER;
//inherit F_QUEST;

void create()
{
	set_name("公孙断", ({ "gongsun duan", "zhanglao", "gongsun" }) );
	set("nickname", "雷电同威");
	set("gender", "男性" );
	set("class", "swordsman");
	set("age", 61);
	set("str", 27);
	set("per", 18);
	set("cor", 25);
	set("cps", 27);
	set("int", 24);

	set("max_force", 1700);
	set("force", 1700);
	set("force_factor", 4);

	set("rank_info/respect", "公孙长老");

	set("long",
		"公孙断是目前封山剑派第十二代中唯一的两个弟子了，现为派中长老。\n"
		"他须发已白，但腰杆依然挺直，以性格火爆而得名「雷电同威」。\n");

	create_family("封山剑派", 12, "长老");

	set("combat_exp", 2000000);
	set("score", 30000);

	set("chat_chance_combat", 75);
	set("chat_msg_combat", ({
		(: perform_action, "sword.counterattack" :)
	}) );

	set_skill("cuff", 50);
	set_skill("parry", 120);
	set_skill("dodge", 90);
	set_skill("sword", 120);
	set_skill("force", 60);
	set_skill("literate", 45);

	set_skill("fonxanforce", 70);
	set_skill("fonxansword", 130);
	set_skill("liuh-ken", 60);
	set_skill("chaos-steps", 110);
	set_skill("spider-array", 85);

        prepare_skill("cuff", "liuh-ken");
	map_skill("cuff", "liuh-ken");
	map_skill("sword", "fonxansword");
	map_skill("parry", "fonxansword");
	map_skill("dodge", "chaos-steps");

	set("inquiry", ([
//		"淳风武馆" : "淳风武馆是先父所创，在下辱承其名，虽忝掌封山门户，不敢忘了先人遗志。",
//		"先人遗志" : "先父临终之时将这武馆交到在下手中，需得好好照看。",
		"柳淳风" : "柳贤侄是我们封山剑派的掌门啊，这都不知道！",
		"name": "我就是封山剑派的长老「雷电同威」公孙断",
//		"here": "这里便是淳风武馆。",
	]) );

	setup();
	carry_object("/obj/weapon/gangjian")->wield();
	carry_object(__DIR__"hat")->wear();
	carry_object("/obj/cloth")->wear();
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


