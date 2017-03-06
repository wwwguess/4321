// daotong.c ��ͯ

#include <ansi.h>
inherit NPC;
#include <random_name.h>


void create()
{
	string name;

        name = get_rndname();
	set_name(name, ({ "daotong", "dao", "tong" }));
	set("long", 
		"�����䵱ɽ��С��ͯ��\n");
        set("title",RED "�䵱��" NOR + GRN "��ͯ" NOR);
	set("gender", "����");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_kee", 150);
	set("max_gin", 100);
	set("force", 150);
	set("max_force", 150);

	set("combat_exp", 2000);
	set("score", 1000);

	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);

	create_family("�䵱��", 5, "����");

	setup();
	
	carry_object("/d/wudang/obj/greyrobe")->wear();
}
