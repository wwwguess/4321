// Npc: /kungfu/class/shaolin/hui-xu.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��������", ({
		"huixu zunzhe",
		"huixu",
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
	set("cor", 28);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("kar", 20);
	set("max_kee", 600);
	set("max_gin", 400);
	set("force", 1600);
	set("max_force", 1600);
	set("force_factor", 50);
	set("combat_exp", 1120000);
	set("score", 6000);

	set_skill("force", 105);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 105);
	set_skill("shaolin-shenfa", 100);
	set_skill("hand", 109);
	set_skill("fengyun-shou", 100);
	set_skill("club", 108);
	set_skill("zui-gun", 108);
	set_skill("parry", 100);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "fengyun-shou");
	map_skill("club", "zui-gun");
	map_skill("parry", "zui-gun");

	prepare_skill("hand", "fengyun-shou");

	create_family("������", 38, "����");

	setup();

        carry_object("/d/shaolin/obj/qimeigun")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}


#include "/class/shaolin/hui.h"

