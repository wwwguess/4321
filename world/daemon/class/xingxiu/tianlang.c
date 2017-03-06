#include <ansi.h>
// tianlang.c ������

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("������", ({ "tianlang zi", "tianlang" }));
	set("title",MAG "������" NOR + YEL "аʿ" NOR);
        set("nickname", RED "��������ʦ��" NOR);
	set("long", 
		"�����Ƕ�����������������ӡ�\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);
	
	set("max_kee", 400);
	set("max_gin", 400);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 15);
	set("combat_exp", 150000);
	set("score", 30000);

	set_skill("force", 70);
//	set_skill("huagong-dafa", 4);
	set_skill("dodge", 50);
	set_skill("zhaixinggong", 40);
	set_skill("strike", 50);
	set_skill("xingxiu-duzhang", 30);
	set_skill("parry", 40);
	set_skill("staff", 70);
  	set_skill("tianshan-zhang", 70);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu-duzhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "xingxiu-duzhang");

	create_family("������", 2, "����");

	setup();
  	carry_object("/obj/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") > -100) {
                command("say ���ɽ���Ҫ�ĺ���������������������ò���ѽ��");
                return;
        }

	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
	if((string)this_player()->query("gender")!="Ů��")
        	this_player()->set("title",HIR "������" NOR + GRN +"аʿ" NOR);
        else
		this_player()->set("title",HIR "������" NOR + GRN +"��Ů" NOR);
}
