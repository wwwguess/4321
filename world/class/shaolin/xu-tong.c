// Npc: /kungfu/class/shaolin/xu-tong.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;


void create()
{
	set_name("��ͨ", ({
		"xu tong",
		"xu",
		"tong",
	}));
	set("long",
		"����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n"
	);



	set("title", HIR "����" NOR + CYN "֪��ɮ" NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_kee", 500);
	set("max_gin", 300);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 100);
	set("combat_exp", 2000);
	set("score", 100);

	set_skill("force", 20);
	set_skill("hunyuan-yiqi", 20);
	set_skill("dodge", 20);
	set_skill("shaolin-shenfa", 20);
	set_skill("strike", 20);
	set_skill("banruo-zhang", 20);
	set_skill("parry", 20);
	set_skill("sword", 20);
	set_skill("damo-jian", 20);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");

	prepare_skill("strike", "banruo-zhang");

	create_family("������", 41, "����");

	setup();

        carry_object("/d/shaolin/obj/xu-cloth")->wear();
}



