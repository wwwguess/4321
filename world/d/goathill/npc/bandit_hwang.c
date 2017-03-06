// bandit_hwang.c

inherit NPC;

void create()
{
	set_name("�ư�", ({ "hwang", "bandit" }) );
	set("title", "Ұ��ɽ����ͷĿ");
	set("nickname", "�����");
	set("gender", "����");
	set("age", 31);
	set("long",
		"�ư�ԭ�ǹ���һ��ɽկ��կ����������Ϊ�ӱܹٸ�׷������Ҳ��ɽ\n"
		"�ܻ������ĳ���������һ�Ը�����ʮ��Ĵ��鳣��ڹ�\��������\��\n"
		"Ҳ���в�������衣\n");
	set("combat_exp", 150000);
	set("attitude", "friendly");
	set("pursuer", 1);

	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 30);

	set("str", 30);
	set("con", 30);
	set("cps", 25);
	set("cor", 26);
	set("spi", 16);
	set("int", 21);
	set("kar", 19);
	set("per", 13);

	set_skill("hammer", 90);
	set_skill("parry", 80);
	set_skill("dodge", 90);
	set_skill("force", 60);
	set_skill("serpentforce", 70);
	map_skill("force", "serpentforce");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 90);
	set_temp("apply/armor", 100);

	setup();
	carry_object(__DIR__"obj/sledge_hammer")->wield();
	carry_object(__DIR__"obj/sledge_hammer")->wield();
	carry_object(__DIR__"obj/boots")->wear();
	carry_object("/obj/cloth")->wear();
	add_money("silver", 40);
}
