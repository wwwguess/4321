// dayou.c c
#include <ansi.h>
inherit NPC;

#include <random_name.h>
void create()
{
	string name;

        name = get_rndname();
	set_name(name, ({ "di zi", "dizi" }));
        set("long",
"��ɽ����\n");
	set("title", GRN "��ɽ" NOR + YEL "��ͯ" NOR);
        set("gender", "����");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_kee", 300);
        set("max_gin", 200);
        set("force", 300);
        set("max_force", 300);
        set("force_factor", 10);
	set("combat_exp", 5000);
        set("score", 100);

	set_skill("force", 30);
	set_skill("huashan-neigong", 30);
	set_skill("cuff", 30);
	set_skill("poyu-quan", 30);
	set_skill("dodge", 30);
	set_skill("huashan-shenfa", 30);
	set_skill("parry", 30);
	set_skill("sword", 30);
	set_skill("huashan-jianfa", 30);

        map_skill("force", "huashan-neigong");
	map_skill("cuff", "poyu-quan");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");

	prepare_skill("cuff", "poyu-quan");

        create_family("��ɽ��", 20, "����");
        setup();
        carry_object("/obj/weapon/changjian")->wield();
}
