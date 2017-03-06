// master.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("½�ò�", ({ "beggarhead", "beggar" }) );

	set("nickname", "��ˮ����");
	set("gender", "����");
	set("age", 52);
	set("long",
		"½�ò���һ���������������ؤ��һ���޾����Ҫ����������ӣ�����\n"
		"���������˶�ʶ�������ϴ�����ʮ�������Ƥ���ң��ⲻ���ǡ����ϻ�\n"
		"����ͷ�������������Į�ϵġ���ˮ���ԡ����ű�����ֻ����½�ò�\n"
		"���ٹ��ܣ���˵������ʱ�����ߡ��˵������������Ĵ����������Ҳ\n"
		"����ȷ����ǰ���½�òƵ����ǲ�����ġ�\n" );
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 24);
	set("con", 29);
	set("spi", 26);
	set("cor", 30);
	set("cps", 30);
	set("kar", 14);
	set("per", 16);
	set("shen_type",-1);
	set("force", 360);
	set("max_force", 180);
	set("force_factor", 10);

	set("combat_exp", 90000);
	set("env/wimpy", 50);
	
	set_skill("claw", 30);
	set_skill("staff", 40);
	set_skill("blade", 25);
	set_skill("throwing", 20);
	set_skill("force", 50);
	set_skill("parry", 50);
	set_skill("dodge", 60);
	set_skill("perception", 20);
	set_skill("stealing", 40);

	set_skill("spicyclaw", 40);
	set_skill("serpentforce", 40);

        prepare_skill("claw", "spicyclaw");
	map_skill("claw", "spicyclaw");
	map_skill("force", "serpentforce");

	create_family("���ϻ�", 4, "��ͷ");

	setup();
}


void attempt_apprentice(object me)
{
	command("look " + me->query("id"));
	if( me->can_afford(100) ) {
		command("say ���ǻ��ϻ�ֻ�ջ��ӣ�" + RANK_D->query_respect(me)
			+ "�����ǻ�ȥ���ɡ�\n");
		return;
	} else {
		command("nod");
		command("recruit " + me->query("id"));
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "beggar");
}


