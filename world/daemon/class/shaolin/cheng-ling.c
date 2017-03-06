// Npc: /kungfu/class/shaolin/cheng-ling.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("����", ({
		"chengling luohan",
		"chengling",
		"riyue",
		"luohan",
	}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n"
	);


	set("title", HIR "����" NOR + CYN "������" NOR + RED "�޺�" NOR);
	set("nickname", RED "��" NOR + YEL "��" NOR + MAG "�޺�" NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("per", 28);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("kar", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 70);
	set("combat_exp", 1700000);
	set("score", 10000);

	set_skill("force", 120);
	set_skill("hunyuan-yiqi", 120);
	set_skill("dodge", 120);
	set_skill("shaolin-shenfa", 125);
	set_skill("club", 110);
	set_skill("weituo-gun", 125);
	set_skill("parry", 120);
	set_skill("buddhism", 85);
	set_skill("literate", 85);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("club", "weituo-gun");
	map_skill("parry", "weituo-gun");
	prepare_skill("club","weituo-gun");

	create_family("������", 37, "����");

	setup();

        carry_object("/d/shaolin/obj/qimeigun")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();

}


#include "/class/shaolin/chengb.h"

