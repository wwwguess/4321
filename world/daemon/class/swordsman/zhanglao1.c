// master.c
// modified by thir in zh 97/7/10
#include <ansi.h>

inherit NPC;
//inherit F_MASTER;
//inherit F_QUEST;

void create()
{
	set_name("唐三星", ({ "tang sanxing", "zhanglao", "tang" }) );
	set("nickname", "铁锁横江");
	set("gender", "男性" );
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

	set("rank_info/respect", "唐长老");

	set("long",
		"唐三星是目前封山剑派第十二代中唯一的两个弟子了，现为派中长老。\n"
		"他须发已白，但腰杆依然挺直，一手封山剑法使的出神入画。\n");

	create_family("封山剑派", 12, "长老");

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
//		"淳风武馆" : "淳风武馆是先父所创，在下辱承其名，虽忝掌封山门户，不敢忘了先人遗志。",
//		"先人遗志" : "先父临终之时将这武馆交到在下手中，需得好好照看。",
		"柳淳风" : "柳贤侄是我们封山剑派的掌门啊，这都不知道！",
		"name": "我就是封山剑派的长老「铁锁横江」唐三星",
//		"here": "这里便是淳风武馆。",
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


