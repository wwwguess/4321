// master.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("陆得财", ({ "beggarhead", "beggar" }) );

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
	set("int", 24);
	set("con", 29);
	set("spi", 26);
	set("cor", 30);
	set("cps", 30);
	set("kar", 14);
	set("per", 16);
	set("shen_type",-1);
	set("force", 360);
	set("max_force", 180);
	set("force_factor", 10);

	set("combat_exp", 90000);
	set("env/wimpy", 50);
	
	set_skill("claw", 30);
	set_skill("staff", 40);
	set_skill("blade", 25);
	set_skill("throwing", 20);
	set_skill("force", 50);
	set_skill("parry", 50);
	set_skill("dodge", 60);
	set_skill("perception", 20);
	set_skill("stealing", 40);

	set_skill("spicyclaw", 40);
	set_skill("serpentforce", 40);

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


