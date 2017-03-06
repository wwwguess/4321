// Npc: /kungfu/class/shaolin/hui-zhen.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��������", ({
		"huizhen zunzhe",
		"huizhen",
		"zunzhe",
	}));
	set("long",
		"����һλ���ް߰׵���ɮ����һϮ�಼������ġ�������Ըߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n"
	);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
	set("per", 28);
	set("cor", 30);

	set("max_kee", 700);
	set("max_gin", 400);
	set("force", 1700);
	set("max_force", 1700);
	set("force_factor", 60);
	set("combat_exp", 1200000);
	set("score", 1000);

	set_skill("force", 110);
	set_skill("hunyuan-yiqi", 110);
	set_skill("dodge", 110);
	set_skill("shaolin-shenfa", 109);
	set_skill("finger", 100);
	set_skill("yizhi-chan", 110);
	set_skill("strike", 110);
	set_skill("banruo-zhang", 110);
	set_skill("sword", 110);
	set_skill("damo-jian", 115);
	set_skill("parry", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "yizhi-chan");
	map_skill("strike", "banruo-zhang");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");

	prepare_skill("sword", "damo-jian");
	prepare_skill("strike", "banruo-zhang");

	create_family("������", 38, "����");

	setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
	mapping mine;
	object me, room;

	me = this_player();

	if (!mapp(mine = me->query("family"))) 
		return;

	if(!( room = find_object("/d/shaolin/cjlou")) )
	room = load_object("/d/shaolin/cjlou");

	if( (mapp(mine = me->query("family")) && mine["family_name"] != "������")
	|| ((!present("daoyi chanshi", room)) && (!present("letter", me)))      )
	{
		  command("say �󵨿�ͽ������ɱ�˴���ؾ��󣬿���!\n");
		  call_out("kill_ob", 0, this_player()); 

	 	  COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));		  
		  return;
	}

	return;
}


