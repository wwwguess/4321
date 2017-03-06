// wujiang.c �佫

inherit NPC;

void create()
{
	set_name("�佫", ({ "wu jiang", "wu", "jiang" }));
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 30);
	set("dex", 16);
	set("long", "��վ�������ȷ��˵���������硣\n");
	set("combat_exp", 95000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("pestle", 60);
	set_skill("xiangmo-chu", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);

	map_skill("pestle", "xiangmo-chu");
	map_skill("parry", "xiangmo-chu");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("force", 400); 
	set("max_force", 400);
	set("jiali", 10);

	setup();
	carry_object("/obj/weapon/xiangmochu")->wield();
	carry_object("/obj/npc/obj/golden_armor")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
