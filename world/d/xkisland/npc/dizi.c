// xkx.di zi.c
// dan

inherit NPC;
 void create()
{
	set_name("弟子", ({
		"di zi",
	
	}));
	set("long",
		"他是一位身材高大的中年人,专职迎候上侠客岛的武林人士.\n"
		
	);


	set("gender", "男性");
	set("attitude", "friendly");


	set("age", 20);
	
	create_family("侠客岛", 3, "弟子");




	setup();

        carry_object("/obj/cloth/blackrobe")->wear();
}
