#include <ansi.h>
// shihou.c ʨ����

inherit NPC;
inherit F_MASTER;

string ask_me();
void consider();

void create()
{
	set_name("ʨ����", ({ "shihou zi", "shihou" }));
	set("title",MAG "������" NOR + YEL "аʿ" NOR);
        set("nickname", RED "�����ɶ�ʦ��" NOR);
	set("long", 
		"�����Ƕ�����Ķ�����ʨ���ӡ�\n"
		"����ʮ���꣬ʨ�����ڣ�һ����֪����������ʿ��\n");
	set("gender", "����");
	set("per", 13);
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("dex", 22);
	
	set("max_kee", 500);
	set("max_gin", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 20);
	set("combat_exp", 200000);
	set("score", 30000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );

	set_skill("force", 60);
	set_skill("huagong-dafa", 40);
	set_skill("dodge", 40);
	set_skill("zhaixinggong", 60);
	set_skill("strike", 70);
	set_skill("xingxiu-duzhang", 40);
	set_skill("parry", 60);
	set_skill("staff", 70);
  	set_skill("tianshan-zhang", 50);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu-duzhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "xingxiu-duzhang");

	create_family("������", 2, "����");

	setup();
  	//carry_object("/clone/weapon/gangzhang")->wield();
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
void init()
{

        object ob;
        mapping fam;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") >=100 && ((fam = ob->query("family")) && fam["master_id"] == "shihou zi"))
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
