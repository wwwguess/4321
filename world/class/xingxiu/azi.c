// azi.c ����

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string ask_me();
void consider();

void create()
{
	set_name("����", ({ "azi" }));
	set("title",MAG "������" NOR + YEL "��Ů" NOR);
        set("nickname", RED "������Сʦ��" NOR);
	set("long", 
		"�����Ƕ�������Ӱ��ϡ�\n"
		"������������������������͸��һ��а����\n");
	set("gender", "Ů��");
	set("per", 23);
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 24);
	
	set("max_kee", 300);
	set("max_gin", 300);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 10);
	set("combat_exp", 50000);
	set("score", 10000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );

	set_skill("force", 40);
	set_skill("huagong-dafa", 30);
	set_skill("dodge", 30);
	set_skill("zhaixinggong", 40);
        set_skill("strike", 30);
	set_skill("xingxiu-duzhang", 40);
	set_skill("parry", 20);
	set_skill("staff", 20);
//	set_skill("tianshan-zhang", 80);
  	set_skill("literate", 30);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu-duzhang");
//	map_skill("parry", "tianshan-zhang");
//	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "xingxiu-duzhang");

	create_family("������", 2, "����");

	setup();
	carry_object("/d/xingxiu/obj/xxqingxin-san");
	carry_object("/d/xingxiu/obj/xxqingxin-san");
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") > 100) {
                command("say ��Խ����Խ��׵������Ե׵ġ�");
                return;
        }
	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
	if((string)this_player()->query("gender")!="Ů��")
        	this_player()->set("title",HIR "������" NOR + GRN +"аʿ" NOR);
        else
		this_player()->set("title",HIR "������" NOR + GRN +"��Ů" NOR);
}
void init()
{

        object ob;
        mapping fam;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") >=100 && ((fam = ob->query("family")) && fam["master_id"] == "azi"))
        {
                command("say ����ɱ��ͬ�����ˣ��������������ʦ����\n");
                command("expell "+ ob->query("id"));
        }
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        command("exert qisuck " + target->query("id"));
}
