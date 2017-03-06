// executioner.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�˾���", ({ "master executioner", "executioner", "master" }) );
	set("title", "ˮ�̸�ִ��ʹ");
	set("nickname", HIC "�� �� ��" NOR);
	set("gender", "����");
	set("age", 28);
	set("long",
		"�˾����ǵ������ֵ�һλ�������������������ʮ��������侹������\n"
		"ˮ�̸�ִ��ʹ��ְλ����ʵ��һλ���򵥵�����˾����Ƿ�ɽ��������\n"
		"������Ľ����ܣ�������Ϊ����ʵʮ�ַ�Ȥ���ֺý����ѣ�˿�������\\n"
		"������ִ���ߵļ��ӡ�\n" );

	set("attitude", "friendly");
	set("combat_exp", 1000000);
	set("score", 200000);

	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 2);

	set("chat_chance", 90);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("sword", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	set_skill("celestial", 100);
	set_skill("celestrike", 100);
	set_skill("pyrobat-steps", 100);
	set_skill("six-chaos-sword", 100);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("sword", "six-chaos-sword");
	map_skill("dodge", "pyrobat-steps");

	setup();

	carry_object(__DIR__"soulimpaler")->wield();
}

