inherit NPC;

void create()
{
	set_name("����", ({"xuan jen","xuan","jen"}) );
	set("gender", "����");
	set("age", 14);
	set("attitude", "heroism");
	set("long",
		"һ������ü��Ŀ���С�к�, ��Ŭ�����ڴ�ɨʯ��\n");
	set("title", "éɽ�ɵڰ˴�����");
	set("class", "taoist");
	set("combat_exp", 1500);
	set("str",25);
	set("max_kee", 350);
	set("max_force", 200);
	set("force",200);
	set("force_factor", 2);
	set("mana", 100);
	set("max_mana", 100);
	set("sen", 150);
	set("max_sen",150);
	set_skill("force", 20);
	set_skill("spells", 15);
	set_skill("staff", 20);
	set_skill("dodge", 15);
	set_skill("parry", 18);
	setup();
	carry_object(__DIR__"obj/broom")->wield();
	carry_object(__DIR__"obj/robe")->wear();
	carry_object(__DIR__"obj/boots")->wear();
}
