// scholar.c

inherit NPC;

void create()
{
	set_name("����", ({ "scholar" }) );
	set("long", "һ���������൱˹�ĵ�������������һ����ҡͷ���Եض�����\n");
	set("age", 23);
	set("attitude", "peaceful");
	set("combat_exp", 10);
	set("env/wimpy", 100);
	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );
	setup();
	carry_object(__DIR__"obj/book");
	carry_object("/obj/cloth")->wear();
}

