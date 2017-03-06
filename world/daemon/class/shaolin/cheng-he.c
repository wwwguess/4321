// Npc: /kungfu/class/shaolin/cheng-he.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("�κ�", ({
		"chenghe luohan",
		"chenghe",
		"jinshen",
		"luohan",
	}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n"
	);


	set("title", HIR "����" NOR + CYN "�޺���" NOR + RED "�޺�" NOR);
	set("nickname", YEL "����" NOR + MAG "�޺�" NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("per", 23);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 2200);
	set("max_force", 2200);
	set("force_factor", 100);
	set("combat_exp", 1800000);
	set("score", 20000);

	set_skill("force", 130);
	set_skill("hunyuan-yiqi", 130);
	set_skill("dodge", 130);
	set_skill("shaolin-shenfa", 130);
	set_skill("sword", 130);
	set_skill("fumo-jian", 135);
	set_skill("parry", 130);
	set_skill("buddhism", 110);
	set_skill("literate", 105);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("sword", "fumo-jian");
	map_skill("parry", "fumo-jian");
	prepare_skill("sword","fumo-jian");

	create_family("������", 37, "����");

	setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/class/shaolin/chengl.h"

