// acrobat.c

inherit NPC;

void create()
{
	set_name("�Ҷ�", ({ "servant" }) );
	set("long", "һ���������˷�ɫ�����ӣ��ع��ؾ��ش���վ��һ�ԡ�\n");
	set("age", 32);
	set("attitude", "peaceful");
	set("combat_exp", 500);
	set("env/wimpy", 30);
	set("str", 23);
	set("cor", 17);
	set("cps", 22);
	set_skill("dodge", 10);
	set_skill("unarmed", 10);
	set_skill("parry", 10);
	setup();
	carry_object("/obj/cloth")->wear();
}

