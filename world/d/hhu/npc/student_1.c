// scholar.c

inherit NPC;

void create()
{
set_name("男生",({"scholar"}) );
        set("gender","男性");
	set("long", "一个看起来相当斯文的书生，正拿著一本书摇头晃脑地读著。\n");
	set("age", 23);
	set("attitude", "peaceful");
	set("combat_exp", 10);
        set("env/wimpy",10);
	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );
	setup();
	carry_object(__DIR__"obj/book");
	carry_object("/obj/cloth")->wear();
}

