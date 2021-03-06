// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
void consider();

void create()
{
	set_name("龙亦凡", ({"island master", "long", "master"}));
	set("nickname", "不败神龙");
	set("gender", "男性");
	set("age", 80);
	set("long", 
		"这难道就是传说中的侠客岛岛主龙亦凡吗？\n他看上去跟一般的中年人无异，可是他已有百岁高龄。\n");
	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("force", 10000);
	set("max_force", 10000);
	set("force_factor", 50);
	set("max_gin",300);
	set("mex_kee",5000);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
	
	set("combat_exp", 2000000);
	set("score", 500000);
	
	set_skill("force", 200);
	set_skill("xiake-force", 150);
	set_skill("unarmed", 200);
	set_skill("parry",200);
	set_skill("xiake-strike", 200);
	set_skill("dodge", 200);
	set_skill("xiake-steps", 200);
	set_skill("move", 150);
	set_skill("literate", 200);
	
	map_skill("force", "xiake-force");
	map_skill("unarmed", "xiake-strike");
	map_skill("dodge", "xiake-steps");
	map_skill("move", "xiake-steps");
	
	set("shen_type",1);
	setup();
}
	
void init()
{
  add_action("give_quest","quest");
}

int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什-
么，你想贿赂我吗？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 你-
好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}


