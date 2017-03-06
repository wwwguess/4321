// wujiang.c �佫

inherit NPC;

void create()
{
	set_name("�佫", ({ "wu jiang", "wu", "jiang" }));
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "��վ�������ȷ��˵���������硣\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("spear", 60);
	set_skill("yangjia-qiang", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);

	map_skill("spear", "yangjia-qiang");
	map_skill("parry", "yangjia-qiang");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("force", 400); 
	set("max_force", 400);
	set("force_factor", 10);

	setup();
	carry_object("/obj/weapon/yinqiang")->wield();
	carry_object("/obj/npc/obj/battle_armor")->wear();
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
