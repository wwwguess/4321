// dfbb.c ��������
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��������", ({ "dong fang bu bai", "dong","dfbb" }));
	//set("nickname", "������̽���");
        set("title",HIR "��"+HIB"��"+HIY "���" NOR + "����");
	set("long", "������������̽�����������\n
		������������ò���绨,��ɫ����\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		("�ٺ�,�书����\n"),
                (: exert_function, "kuihua" :),
		(: exert_function, "recover" :),
        }) );

	set("max_kee", 5000);
	set("max_gin", 5000);
	set("force", 8000);
	set("max_force", 5000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 1000000);

	set_skill("force", 100);
	set_skill("kuihua-shengong", 150);
	set_skill("dodge", 150);
	set_skill("mo-zhang-jue", 150);
	set_skill("unarmed", 100);
	set_skill("mo-jian-jue", 150);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("literate", 100);

	map_skill("force", "kuihua-shengong");
	map_skill("unarmed", "mo-zhang-jue");
	map_skill("parry", "mo-jian-jue");
	map_skill("sword", "mo-jian-jue");
	map_skill("dodge", "kuihua-shengong");
	create_family("�������", 1, "����");
	setup();

	carry_object(__DIR__"obj/dress");
        carry_object(__DIR__"obj/flower_boot");
	carry_object(__DIR__"obj/needle")->wield();
}

void init()
{
	::init();
}

void attempt_apprentice(object me)
 {	
	command("say �Ҳ���ͽ��.\n");
 }


