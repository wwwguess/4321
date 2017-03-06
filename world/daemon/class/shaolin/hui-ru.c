// Npc: /kungfu/class/shaolin/hui-ru.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��������", ({
		"huiru zunzhe",
		"huiru",
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
	set("cor", 30);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("kar", 20);
	set("max_kee", 600);
	set("max_gin", 400);
	set("force", 1600);
	set("max_force", 1600);
	set("force_factor", 50);
	set("combat_exp", 1100000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("sword", 100);
	set_skill("fumo-jian", 100);
	set_skill("parry", 100);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("sword", "fumo-jian");
	map_skill("parry", "fumo-jian");

	create_family("������", 38, "����");

	setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}



