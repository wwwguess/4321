// bandit.c

inherit NPC;

void create()
{
	set_name("����צ��", ({ "bandit minion", "bandit", "minion" }) );
	set("gender", "����");
	set("age", 26);
	set("long",
		"һ�������׶�����ˣ����Ϻü��������ĵ��̣���������֪�������ǡ�\n");
	set("combat_exp", 6000);
	set("attitude", "aggressive");
	set_skill("blade", 40);
	set_skill("parry", 40);
	set_skill("dodge", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 30);
	setup();
	carry_object(__DIR__"obj/steel_blade")->wield();
	add_money("silver", 10);
}
