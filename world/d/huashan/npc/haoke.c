// haoke.c ����

inherit NPC;

void create()
{
	set_name("��������", ({ "jianghu haoke", "haoke" }));
	set("long", 
		"һ�������뺴֮ɫ�Ľ������͡�\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "heroism");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_kee", 300);
	set("max_gin", 200);
	set("force", 300);
	set("max_force", 300);

	set("combat_exp", 2000);

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);

	setup();
	carry_object("/obj/weapon/changjian")->wield();
}
