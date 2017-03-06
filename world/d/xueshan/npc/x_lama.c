// x_lama.c 小喇嘛

inherit NPC;

void create()
{
        set_name("小喇嘛",({
		"xiao lama",
		"xiao",
		"lama",
	}));
	set("long",
                "这是雪山寺的小喇嘛，一脸的稚气，看来刚入门不久。\n"
	);


	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

        set("age", 13);
        set("shen_type", 0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_kee", 100);
	set("max_gin", 100);
	set("force", 100);
	set("max_force", 100);
	set("combat_exp", 50);

	setup();
	carry_object("/d/xueshan/obj/y-jiasha1")->wear();
}
