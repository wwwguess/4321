// boss.c

inherit NPC;

void create()
{
	set_name("��¥����", ({ "hotel guard", "guard" }) );
	set("long",
		"һ���������µ��ˣ�������������������飬��Ȼ�Ǹ������ӡ�\n");
	set("age", 29);
	set("attitude", "peaceful");
	set("combat_exp", 100000);
	set("bellicosity", 400);
	set("force", 1000);
	set("max_force", 500);
	set("force_factor", 15);

	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("dodge", 70);
	set_skill("force", 65);

	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 20);

	setup();

	add_money("coin", 120);
	carry_object("/obj/longsword")->wield();
	carry_object("/obj/cloth")->wear();
}

int accept_fight(object me)
{
	command("say �ƹ���н�������׼�κ����������ܣ�");
	return 0;
}

void accept_kill(object me)
{
	mixed *fellow;

	fellow = all_inventory(environment())->help_hotel_guard(this_object(), me);
	fellow -= ({ 0 });
	if( sizeof(fellow) ) {
		command("say ��ǿ�˴����... ��ȥ���٣�");
		me->set("vendetta/authority", 1);
	}
}

int help_hotel_guard(object me, object foe)
{
	if( me==this_object() ) return 0;
	command("say ��ʲô����");
	kill_ob(foe);
	return 1;
}
