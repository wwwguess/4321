// bandit.c

inherit NPC;

void create()
{
	set_name("��������", ({ "bandit leader", "bandit", "leader" }) );
	set("gender", "����");
	set("age", 31);
	set("long",
		"������˿������൱ǿ��������������Ķ����Ϳ��Կ��ó�������Ȼ\n"
		"�������书\��Ӳ�֣������Ƿ���֮����\n");
	set("combat_exp", 14000);
	set("attitude", "aggressive");
	set_skill("axe", 70);
	set_skill("parry", 60);
	set_skill("dodge", 70);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 80);
	setup();
	carry_object(__DIR__"obj/hand_axe")->wield();
	carry_object(__DIR__"obj/hand_axe")->wield();
	add_money("silver", 10);
}
