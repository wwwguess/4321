// qipaiguan.c

inherit NPC;

void create()
{
	set_name("旗牌官", ({ "qipai guan","wu" }));
	set("gender", "男性");
	set("age", 30);
	set("long",
        	"他就是才升任旗牌官的嘉峪关的武旗牌。\n");

	set("attitude", "peaceful");

	set("str", 27);
	set("int", 25);

	set("combat_exp", 80000);
	
	set("chat_chance", 8);
	set("chat_msg", ({
	"武旗牌说道：你有没有搞错啊！来这□不给我们李将军过路费，你找死啊！\n",
	}) );
	
	set("inquiry", ([
		"嘉峪关" : "你问问李将军吧，我不是很清楚。\n",
		"后备兵" : "后备兵就..........你想做什么？找死啊。\n",
	]) );
	
	set("force", 400);
	set("max_force", 400);
	set("force_factor", 5);

	set_skill("dodge", 60);
	set_skill("blade", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("unarmed", 65);
	
	setup();

	carry_object( __DIR__"obj/blade")->wield();
}

		
