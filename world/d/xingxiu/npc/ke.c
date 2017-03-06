// npc: /d/xingxiu/npc/ke.c
// Jay 3/27/96

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("ŷ����", ({ "ouyang ke", "ouyang", "ke" }));
        set("long", "����ҡ���ȣ��������š�\n");
        set("title",CYN "����ɽׯ" NOR + MAG "��ׯ��" NOR);
        set("gender", "����");
        set("age", 27);

        set_skill("unarmed", 50);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("force", 50);

        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
	set("per", 28);

        set("max_kee", 800);
        set("max_gin", 600);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 20);
        set("combat_exp", 50000);
        set("score", 5000);

        set("attitude", "peaceful");
        set("shen_type", -1);
        create_family("����ɽ", 2, "����");

        setup();
}
