// lady.c

inherit NPC;

void create()
{
	set_name("����", ({ "lady" }) );
	set("long", "һ�����λ����ĸ��������������ϵ�Ĥ������\n");
	set("age", 32);
	set("gender", "Ů��");
	set("attitude", "peaceful");
	set("combat_exp", 10);
	set("env/wimpy", 100);
	setup();
	carry_object(__DIR__"obj/lady_dress")->wear();
	carry_object(__DIR__"obj/silver_clasp")->wear();
	add_money("silver", 10);
}

