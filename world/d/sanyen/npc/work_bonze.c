// monk.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("ɨ��ɮ", ({ "work bonze","bonze" }) );
	set("gender", "����" );
	set("class", "bonze");
	set("age", 26);
	set("str", 16);
	set("cor", 24);
	set("cps", 12);
	set("int", 20);
	set("long",
		"һ���ʷ����ֵ�ɮ��, ��������ɨ����һ��ûһ�µ�ɨ��, ��֪����\n"
		"ƽ��Ҳ�����������\n" );

	set("combat_exp", 200);
	set("attitude", "friendly");

	set("max_force", 300);
	set("force", 300);

	set_skill("force", 20);
	set_skill("unarmed", 25);
        set_skill("staff",20);
        set_skill("cloudstaff",15);
	set_skill("dodge", 10);
	set_skill("lotusforce", 15);

	map_skill("force", "lotusforce");
        map_skill("staff", "cloudstaff");

	setup();

    carry_object(__DIR__"obj/broom")->wield();
	carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/shoe")->wear();
}

int accept_fight(object me)
{
    command("say �����ӷ�ƶɮ�书\��΢��ʩ����Ҫ��������Ц��\n");
    return 0;
}
