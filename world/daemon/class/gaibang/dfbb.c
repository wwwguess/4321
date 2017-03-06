// dfbb.c ��������
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
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
                ("\n"+ RED "��������˵�����ٺ�,�书������\n\n" NOR),
                (: exert_function, "kuihua" :),
		(: exert_function, "recover" :),
        }) );

	set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
	set("force", 8000);
	set("max_force", 5000);
	set("force_factor", 100);
	set("combat_exp", 2000000);
	set("score", 1000000);

	set_skill("force", 100);
	set_skill("kuihua-shengong", 150);
	set_skill("dodge", 150);
	set_skill("mo-zhang-jue", 150);
	set_skill("strike", 100);
	set_skill("mo-jian-jue", 150);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("literate", 100);
        set_skill("daguanming",150);

	map_skill("force", "kuihua-shengong");
	map_skill("strike", "mo-zhang-jue");
	map_skill("parry", "mo-jian-jue");
	map_skill("sword", "mo-jian-jue");
	map_skill("dodge", "kuihua-shengong");

	prepare_skill("strike", "mo-zhang-jue");

	create_family("�������", 1, "����");
	setup();

           carry_object(__DIR__"obj/dress")->wear();
           carry_object(__DIR__"obj/flower_boot")->wear();
	carry_object(__DIR__"obj/needle")->wield();
}

void init()
{
	::init();
       add_action("give_quest","quest");
}

void attempt_apprentice(object ob)
 {	

	string title1;

        if ((int)ob->query("shen") > 100) {
                command("say ��Խ����Խ��׵������Ե׵ġ�");
                return;
        }
       if ((int)ob->query("shen") > -10000) {
                command("say �㻹�����ĺ�����!");
                return;
        }
       if ((int)ob->query("combat_exp") < 100000) {
                command("say �㻹̫����!");
                return;
        }



	if(this_player()->query("family/family_name")!="�������")
         {
	          write( RANK_D->query_respect(this_player()) +
                "������ذ�!�Ҳ��ս���֮��\n");
          return;
         }
	 command("say �ðɣ��Ҿ��������ˡ�\n");
                title1=this_player()->query("title");
	command("recruit " + ob->query("id"));
                this_player()->set("title", title1);
	return;
 }


