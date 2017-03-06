// Npc: /kungfu/class/shaolin/cheng-guan.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
//inherit F_QUEST;

void create()
{
	set_name("�ι�", ({
		"chengguan luohan",
		"chengguan",
		"xianglong",
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
	set("per", 30);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("kar", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 2100);
	set("max_force", 2100);
	set("force_factor", 90);
	set("combat_exp", 1700000);
	set("score", 10000);

	set_skill("force", 125);
	set_skill("hunyuan-yiqi", 125);
	set_skill("dodge", 125);
	set_skill("shaolin-shenfa", 120);
	set_skill("hand", 110);
	set_skill("fengyun-shou", 120);
	set_skill("parry", 125);
	set_skill("blade", 120);
	set_skill("xiuluo-dao",125);
	set_skill("buddhism", 95);
	set_skill("literate", 85);

	map_skill("blade", "xiuluo-dao");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "fengyun-shou");

	prepare_skill("blade","xiuluo-dao");
	prepare_skill("hand", "fengyun-shou");

	create_family("������", 37, "����");

	setup();

	carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/class/shaolin/chengl.h"
