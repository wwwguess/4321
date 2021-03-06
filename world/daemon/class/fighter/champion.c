// servant.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("於兰天武", ({ "master champion", "champion", "master" }) );
	set("title", "水烟阁传功\使");
	set("nickname", "大天邪");
	set("gender", "男性");
	set("age", 54);
	set("long",
		"於兰天武是当今皇上的叔父，但是他毕生浸淫武学，甘愿抛弃荣华富\n"
		"以换取水烟阁传功\使一职，以便阅\读水烟阁中所藏的武学典籍，无论\n"
		"你有什麽武学上的疑难，他都能为你解答。\n");

	set("attitude", "peaceful");
          set("combat_exp", 4500000);
        set("score",50000);

	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("atman", 1000);
	set("max_atman", 1000);

	set("force", 4000);
	set("max_force", 2400);
	set("force_factor" ,90);

	set("mana", 1000);
	set("max_mana", 1000);

	set("inquiry", ([
		"武学": "武学之道....嗯....只可意会，不可言喻。\n",
		"水烟阁": "水烟阁乃是历届武林盟主的行馆，你有什麽事要见武林盟主？\n",
		"拜师": "哦....老夫向来有个规矩，凡是想拜我为师的，得接我三招不死，你想试试(accept test)？\n"
	]) );

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );
	create_family("天邪派", 15, "弟子");
	assign_apprentice("弟子", 0);

	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("blade", 200);
	set_skill("parry", 200);
	set_skill("dodge", 150);
	set_skill("throwing", 150);

	set_skill("celestial", 200);
	set_skill("celestrike", 200);
	set_skill("spring-blade", 200);
	set_skill("pyrobat-steps", 150);

	map_skill("force", "celestial");
	prepare_skill("strike", "celestrike");
	map_skill("blade", "spring-blade");
	map_skill("dodge", "pyrobat-steps");

	set("per",27);

	setup();

	carry_object(__DIR__"houndbane")->wield();
	carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"dragon_armor")->wear();
}

void init()
{
	::init();
	add_action("do_accept", "accept");
}


int do_accept(string arg)
{
	mapping guild;

	if( !this_player()->query("can_speak") ) return 0;

	if( arg== "test" ) {
		say("\n於兰天武点了点头，说道：很好，这是第一招....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("於兰天武叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
			return 1;
		}
		say("\n於兰天武说道：这是第二招....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("於兰天武「哼」地一声，说道：便是有这许\多不怕死的家伙....\n");
			return 1;
		}
		say("\n於兰天武说道：第三招来了....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("於兰天武叹道：可惜，难道老夫一身武功\竟无传人....\n");
			return 1;
		}
		say("\n於兰天武哈哈大笑，说道：今日老夫终於觅得一个可造之才！\n\n");
		command("recruit " + this_player()->query("id") );
		return 1;
	}
	return 0;
}

