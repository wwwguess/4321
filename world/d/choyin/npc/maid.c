// maid.c

inherit NPC;

void create()
{
	set_name("Ѿ��", ({ "maid" }) );
	set("long", "һ��������Ǯ�˼�С���Ѿ�ߣ������ĵ���Ū���½ǡ�\n");
	set("age", 17);
	set("gender", "Ů��");
	set("attitude", "peaceful");
	set("combat_exp", 10);
	set("env/wimpy", 100);
	set("inquiry", ([
		"here": "���ﰡ��������������������Ĵ���������",
	]) );
	setup();
	carry_object("/obj/cloth")->wear();
}

