// xkx.zhang san.c
// dan

inherit NPC;



void create()
{
	set_name("张三", ({
		"zhang san",
		"zhang",
	
	}));
	set("long",
		"他是一位身材高大的中年人，笑容可掬，是侠客岛的赏善使者。\n"
		
	);


	set("gender", "男性");
	set("attitude", "friendly");


	set("age", 40);
	
	create_family("侠客岛", 2, "弟子");




	setup();

        carry_object("/obj/cloth/blackrobe")->wear();
}
