// Npc: /d/shaolin/npc/xiao-tong.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��ʹ", ({
		"xiao shami",
		"xiao",
		"shami",
	}));
        set("title", HIR "����" NOR + CYN "Сɳ��" NOR);
	set("long",
		"����һλδͨ���ʵ�������У����Ϲ����������Ц��\n"
	);


	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 10);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_kee", 100);
	set("max_gin", 100);
	set("force", 100);
	set("max_force", 100);
	set("combat_exp", 500);
	set("score", 100);

	set_skill("force", 8);
	set_skill("dodge", 8);
	set_skill("unarmed", 8);
	set_skill("parry", 8);


	setup();

}



