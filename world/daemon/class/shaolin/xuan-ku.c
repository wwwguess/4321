// Npc: /kungfu/class/shaolin/xuan-ku.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("�����ʦ", ({
		"xuanku dashi",
		"xuanku",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿�ػ����ġ�������ݸߣ�\n"
		"�����������ƣ��ֱ۴������¶���ƺ��þ���˪��\n"
	);


	set("nickname", CYN "�޺���" NOR + RED "����" NOR);
        set("title", HIR "����" NOR + MAG "��ɮ" NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("per", 18);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
	set("max_kee", 1500);
	set("max_gin", 1000);
	set("force", 2500);
	set("max_force", 2500);
	set("force_factor", 150);
	set("combat_exp", 3200000);
	set("score", 30000);

	set_skill("force", 150);
	set_skill("hunyuan-yiqi", 150);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 150);
	set_skill("parry", 150);
	set_skill("cuff", 140);
	set_skill("staff", 150);
	set_skill("blade", 120);
	set_skill("sword", 140);
	set_skill("luohan-quan", 130);
	set_skill("weituo-gun", 140);
	set_skill("xiuluo-dao", 150);
	set_skill("fumo-jian", 150);
	set_skill("buddhism", 120);
	set_skill("literate", 120);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "luohan-quan");
	map_skill("cuff", "luohan-quan");
	map_skill("staff", "weituo-gun");
	map_skill("blade", "xiuluo-dao");
	map_skill("sword", "fumo-jian");

	prepare_skill("blade","xiuluo-dao");
	prepare_skill("cuff", "luohan-quan");

	create_family("������", 36, "����");

	set("inquiry", ([
		"ʮ���޺���"       : (: ask_me :),
		"�޺�����"	   : (: ask_me :)
	]));

	setup();

        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

#include "/class/shaolin/xuan-ku.h"
#include "/class/shaolin/xuan1.h"




