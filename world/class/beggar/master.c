// master.c

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
inherit F_QUEST;

void consider();

void create()
{
	set_name("½�ò�", ({ "beggarhead", "beggar", "master" }) );

	set("replica_ob", __DIR__"fake_master");
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
	set("con", 30);
	set("spi", 20);
	set("int", 24);
	set("cor", 30);
	set("cps", 30);
	set("kar", 15);
	set("per", 18);
	set("shen_type",-1);

	set("force", 3600);
	set("max_force", 1800);
	set("force_factor", 70);

	set("combat_exp", 1000000);
	set("score", 200000);
	set("env/wimpy", 50);
	
	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
	}) );

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :)
	}) );

	set_skill("claw", 80);
	set_skill("staff", 90);
	set_skill("blade", 70);
	set_skill("throwing", 60);
	set_skill("force", 100);
	set_skill("parry", 60);
	set_skill("dodge", 100);
	set_skill("perception", 80);
	set_skill("stealing", 100);

          set_skill("spicyclaw", 100);
          set_skill("serpentforce", 100);

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

void init()
{
	::init();
        add_action("give_quest", "quest");
}

// if not allow quest ,then return 0
//int valid_quest() {
//	return 1;
//}


// check if bribe is valid
/*
int valid_bribe(object who,int val) {
	message_vision( (this_object())->query("name")+"��$Nһ˦���䣬˵���� ʲô�������¸���𣿣�\n",who);
	return(0);
}

// called when not finish the task
int quest_punish(object who) {
	message_vision( (this_object())->query("name")+"��$Nһ˦���䣬˵���� �汿����ú�ѧѧ������Ҫ����ɣ�\n" ,who);
    who->set("quest",0);
    return(0);
}
*/ 
