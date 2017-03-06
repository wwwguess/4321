// Npc: /kungfu/class/shaolin/cheng-gin.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("�ξ�", ({
		"chengjing luohan",
		"chengjing",
		"jingjing",
		"luohan",
	}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n"
	);


	set("title", HIR "����" NOR + CYN "�޺���" NOR + RED "�޺�" NOR);
	set("nickname", GRN "����" NOR + MAG "�޺�" NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("per", 26);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("kar", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 2100);
	set("max_force", 2100);
	set("force_factor", 80);
	set("combat_exp", 1700000);
	set("score", 11000);

	set_skill("force", 124);
	set_skill("hunyuan-yiqi", 125);
	set_skill("dodge", 115);
	set_skill("staff",120);
	set_skill("wuchang-zhang",120);
	set_skill("shaolin-shenfa", 120);
	set_skill("claw", 110);
	set_skill("longzhua-gong", 110);
	set_skill("parry", 120);
	set_skill("buddhism", 90);
	set_skill("literate", 85);

	map_skill("staff","wuchang-zhang");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "longzhua-gong");
	prepare_skill("staff","wuchang-zhang");
	prepare_skill("claw", "longzhua-gong");

	create_family("������", 37, "����");

	setup();
	carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/class/shaolin/chengl.h"

