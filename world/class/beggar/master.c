// master.c

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
inherit F_QUEST;

void consider();

void create()
{
	set_name("陆得财", ({ "beggarhead", "beggar", "master" }) );

	set("replica_ob", __DIR__"fake_master");
	set("nickname", "黑水伏蛟");
	set("gender", "男性");
	set("age", 52);
	set("long",
		"陆得财是一个浑身脏兮兮的老丐，一副无精打采要死不活的样子，可是\n"
		"武林中人人都识得他身上打著二十三个结的皮酒囊，这不但是「花紫会\n"
		"」龙头的信物，更是名镇漠南的「黑水伏蛟」独门兵器，只不过陆得财\n"
		"行踪诡密，据说各处随时都有七、八的他的替身在四处活动，所以你也\n"
		"很难确定眼前这个陆得财到底是不是真的。\n" );
	set("attitude", "peaceful");

	set("str", 30);
	set("con", 30);
	set("spi", 20);
	set("int", 24);
	set("cor", 30);
	set("cps", 30);
	set("kar", 15);
	set("per", 18);
	set("shen_type",-1);

	set("force", 3600);
	set("max_force", 1800);
	set("force_factor", 70);

	set("combat_exp", 1000000);
	set("score", 200000);
	set("env/wimpy", 50);
	
	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
	}) );

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :)
	}) );

	set_skill("claw", 80);
	set_skill("staff", 90);
	set_skill("blade", 70);
	set_skill("throwing", 60);
	set_skill("force", 100);
	set_skill("parry", 60);
	set_skill("dodge", 100);
	set_skill("perception", 80);
	set_skill("stealing", 100);

          set_skill("spicyclaw", 100);
          set_skill("serpentforce", 100);

       prepare_skill("claw", "spicyclaw");
       map_skill("claw", "spicyclaw");
	map_skill("force", "serpentforce");

	create_family("花紫会", 4, "龙头");

	setup();
}


void attempt_apprentice(object me)
{
	command("look " + me->query("id"));
	if( me->can_afford(100) ) {
		command("say 我们花紫会只收化子，" + RANK_D->query_respect(me)
			+ "您还是回去享福吧。\n");
		return;
	} else {
		command("nod");
		command("recruit " + me->query("id"));
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "beggar");
}

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
