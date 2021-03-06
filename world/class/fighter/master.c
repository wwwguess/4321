// shiao.c

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
void consider();

void create()
{
	set_name("萧辟尘", ({ "master fighter", "master", "fighter" }) );

	set("nickname", "小天邪");
	set("gender", "男性");
	set("age", 24);
	set("long",
		"萧辟尘自幼生长於岚城之中，看起来仙风道骨，不食人间烟火。\n");
	set("attitude", "peaceful");
        set("shen_type",-1);

	set("str", 26);
	set("cor", 30);
	set("int", 24);
	set("cps", 30);

	set("force", 4000);
	set("max_force", 2400);
	set("force_factor", 30);

	set("combat_exp", 1000000);
	set("score", 200000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: consider :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 100);
	set_skill("sword", 60);
	set_skill("blade", 40);
	set_skill("throwing", 40);
	set_skill("force", 100);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("literate", 60);
	set_skill("perception", 80);

	set_skill("six-chaos-sword", 80);
	set_skill("celestial", 100);
	set_skill("celestrike", 100);
	set_skill("pyrobat-steps", 50);

	map_skill("sword", "six-chaos-sword");
	map_skill("parry", "six-chaos-sword");
	map_skill("force", "celestial");
        prepare_skill("strike", "celestrike");
	map_skill("strike", "celestrike");
	map_skill("dodge", "pyrobat-steps");
	map_skill("move", "pyrobat-steps");

	create_family("天邪派", 16, "弟子");

	set("shen_type",-1);
	setup();

	carry_object("/obj/longsword");
	carry_object(__DIR__"icy_boot")->wear();
	carry_object(__DIR__"icy_girth")->wear();
	carry_object(__DIR__"icy_cloth")->wear();
	carry_object(__DIR__"icy_ribbon")->wear();
}

void init()
{
	add_action("do_swear", "swear");
        add_action("give_quest","quest");
}

void attempt_apprentice(object me)
{
	if( me->query_temp("pending/celestial_swear") ) {
		command("say 多说无益，若不发誓恪守门规，便是跪著求我也没用。");
		return;
	} else {
		command("say 我天邪派门规甚严，" + RANK_D->query_respect(me)
			+ "如果真的有心，且发个誓(swear)来。");
		me->set_temp("pending/celestial_swear", 1);
	}
}

int do_swear(string arg)
{
	if( !this_player()->query_temp("pending/celestial_swear") )
		return 0;
	if( !arg ) return notify_fail("你要发什麽誓？\n");
	this_player()->set_temp("pending/celestial_swear", 0);
	message_vision("$N发誓道：" + arg + "\n", this_player());
	if( strsrch(arg, "守") >=0 && strsrch(arg, "门规") >=0
	&&	strsrch(arg, "不") <0) {
		command("smile");
		command("say 这就是了。\n");
		command("recruit " + this_player()->query("id"));
	} else {
		command("say 你发的是什麽鬼誓，别以为我没听到！");
	}
	return 1;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_availavble", -1);
}

void consider()
{
	int i, flag = 0;
	object *enemy;

	enemy = query_enemy() - ({ 0 });
	for(i=0; i<sizeof(enemy); i++) {
		if( !living(enemy[i]) ) continue;
		if( enemy[i]->query_temp("weapon") ) {
			flag++;
			if(	!query_temp("weapon") ) {
				command("say " + RANK_D->query_respect(enemy[i]) + "既然使兵刃，在下空手接招未免不敬。");
				command("wield sword");
				command("say 进招吧！");
				break;
			}
		}
	}
	if( !flag && query_temp("weapon") ) {
		if( sizeof(enemy) > 1 )
			command("say 嗯... 既然" + chinese_number(sizeof(enemy)) + "位都是空手，在下理当奉陪！");
		else
			command("say 既然" + RANK_D->query_respect(enemy[0]) + "不使兵刃，在下自然奉陪！\n");
		command("unwield sword");
	}
}


// check if bribe is valid
/*
int valid_bribe(object who,int val) {
	message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
	return(0);
}

// called when not finish the task
int quest_punish(object who) {
	message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 真笨，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}
*/
