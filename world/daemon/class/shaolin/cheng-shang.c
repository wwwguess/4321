// Npc: /kungfu/class/shaolin/cheng-shang.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("����", ({
		"chengshang luohan",
		"chengshang",
		"guangli",
		"luohan",
	}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n"
	);


	set("title", HIR "����" NOR + CYN "������" NOR + RED "�޺�" NOR);
	set("nickname", GRN "����" NOR + MAG "�޺�" NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("per", 21);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("kar", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 1900);
	set("max_force", 1900);
	set("force_factor", 60);
	set("combat_exp", 1700000);
	set("score", 10000);

	set_skill("force", 125);
	set_skill("hunyuan-yiqi", 115);
	set_skill("dodge", 115);
	set_skill("shaolin-shenfa", 115);
	set_skill("sword", 120);
	set_skill("damo-jian", 125);
	set_skill("parry", 115);
	set_skill("buddhism", 85);
	set_skill("literate", 85);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");

	create_family("������", 37, "����");

	setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/class/shaolin/chengb.h"

