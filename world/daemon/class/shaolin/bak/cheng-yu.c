// Npc: /kungfu/class/shaolin/cheng-yu.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("����", ({
		"chengyu luohan",
		"chengyu",
		"xumi",
		"luohan",
	}));
	set("long",
		"����һλ�뷢���׵���ɮ������һϮ��ߺڲ����ġ��������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ����������书��\n"
	);



	set("title", HIR "����" NOR + CYN "������" NOR + RED "�޺�" NOR);
	set("nickname", GRN "����" NOR + MAG "�޺�" NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 100);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 85);
	set_skill("hunyuan-yiqi", 85);
	set_skill("dodge", 85);
	set_skill("shaolin-shenfa", 85);
	set_skill("staff", 90);
	set_skill("pudu-zhang", 95);
	set_skill("parry", 85);
	set_skill("buddhism", 85);
	set_skill("literate", 85);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("staff", "pudu-zhang");
	map_skill("parry", "pudu-zhang");

	create_family("������", 37, "����");

	setup();

        carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/class/shaolin/chengb.h"

