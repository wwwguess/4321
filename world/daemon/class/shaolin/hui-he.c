// Npc: /kungfu/class/shaolin/hui-he.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
//inherit F_QUEST;
string ask_me();

void create()
{
	set_name("慧合尊者", ({
		"huihe zunzhe",
		"huihe",
		"zunzhe",
	}));
	set("long",
		"他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，\n"
		"太阳穴微凸，双目炯炯有神。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("cor", 24);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("kar", 20);
	set("max_kee", 550);
	set("max_gin", 400);
	set("force", 1400);
	set("max_force", 1400);
	set("force_factor", 50);
	set("combat_exp", 1100000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 101);
	set_skill("shaolin-shenfa", 100);
	set_skill("finger", 98);
	set_skill("nianhua-zhi", 108);
	set_skill("parry", 100);
	set_skill("sword", 105);
	set_skill("damo-jian", 105);
	set_skill("buddhism", 80);
	set_skill("literate", 80);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");

	prepare_skill("sword", "damo-jian");

	create_family("少林派", 38, "弟子");

	set("inquiry", ([
		"买铁" :    (: ask_me :),
	]));

	setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

#include "/class/shaolin/hui.h"

string ask_me()
{
	return "买铁？ 他现在又不缺铁！ 前天老乔不是刚送来一堆铁块，铁手掌什麽的给他吗？！";
}
/*
void init()
{
   ::init();
   add_action("give_quest","quest");
}
// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N双手合十，说道： 罪过罪过。\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N双手合十，说道： 善哉善哉，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}
*/
