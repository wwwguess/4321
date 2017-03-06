inherit NPC;

void create()
{
	set_name("Ğ¡É³ÃÖ", ({ "xiao shami","shami"}) );
	set("gender", "ÄĞĞÔ" );
	set("class", "bonze");
	set("age", 15);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	set("kee", 500);
	set("max_kee", 500);
	set("gin", 100);
	set("max_gin", 100);
	set("force", 100);
	set("max_force", 100);
	set("jiali", 10);
	set("combat_exp", 8000);
	set("score", 1000);

	set_skill("force", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("parry", 50);
	set_skill("buddhism", 100);
	set_skill("literate", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	
	setup();
//	carry_object("/d/baituo/obj/jiasha")->wear();
}

