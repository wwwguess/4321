// huang-yaoshi.c -��ҩʦ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void consider();

void create()
{
	set_name("��ҩʦ", ({ "huang yaoshi", "huang", "yaoshi" }) );

	set("nickname",  RED "��а" NOR);
	set("title", GRN "�һ�����" NOR);
	set("gender", "����");
	set("age", 60);
	set("long",
                "���ǵ�������̩��֮һ���ųƶ�а��\n"
                "���˾�˵�Ը�Ź֣����ѽӽ���\n"
	);
	set("attitude", "peaceful");

	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);

	set("force", 3000);
	set("max_force", 3000);
	set("force_factor", 100);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
	set("max_kee", 5000);
	set("max_gin", 500);

	set("combat_exp", 1500000);
	set("score", 200000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
	


        set_skill("force", 150);
	set_skill("taohua-force", 150);
        set_skill("dodge", 150);
        set_skill("baguabu", 150);
        set_skill("strike", 150);
        set_skill("luoying-zhang",100);
        set_skill("hand",100);
        set_skill("lanhua-shou", 150);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("yuxiao-jian", 150);
        set_skill("literate", 200);
       	set_skill("qimen-bagua", 150);

        map_skill("force", "taohua-force");
        map_skill("dodge", "baguabu");
        map_skill("hand", "lanhua-shou");
        map_skill("strike","luoying-zhang");
        map_skill("parry", "yuxiao-jian");
        map_skill("sword", "yuxiao-jian");
        prepare_skill("hand","lanhua-shou");
        prepare_skill("strike", "luoying-zhang");

        create_family("�һ���", 1, "��ɽ��ʦ");
        set("class", "ƽ��");

        setup();
        carry_object("/obj/weapon/yuxiao")->wield();
}



void attempt_apprentice(object ob)  
{       
         if ((string)this_player()->query("family/family_name")=="�һ���")
         {if (this_player()->query_skill("qimen-bagua",1)<80)
            { command("say �����ɲ���֮�����Ű���,�����򲻹���");
             return;
             }
            else {command("say �ðɣ��Ҿ��������ˡ�");
                 command("recruit " + ob->query("id"));
                 }
          }
         
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        	if((string)ob->query("gender")!="Ů��")
                {
			ob->set("title",RED "�һ���" NOR + GRN +"����" NOR);
			return;
		}
	        else
                {
			ob->set("title",RED "�һ���" NOR + GRN +"Ů����" NOR);
			return;
		}
       
}
void re_rank(object student)
{
        if (student->query("age")<20)
        {
        	if((string)student->query("gender")!="Ů��")
		{
                	student->set("title",RED "�һ���" NOR + GRN +"Сͯ" NOR);
			return;
		}
        	else
		{
                	student->set("title",RED "�һ���" NOR + GRN +"Ůͯ" NOR);
			return;
		}
        }
        else 
	{
        	if((string)student->query("gender")!="Ů��")
                {
			student->set("title",RED "�һ���" NOR + GRN +"����" NOR);
			return;
		}
	        else
                {
			student->set("title",RED "�һ���" NOR + GRN +"Ů����" NOR);
			return;
		}
        }
}

void init()
{
 add_action("give_quest","quest");
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
     
        command("exert tanzhi " + target->query("id"));
}

/*void init()
{
	::init();
        add_action("give_quest", "quest");
}
*/
// if not allow quest ,then return 0
//int valid_quest() {
//	return 1;
//}


// check if bribe is valid
int valid_bribe(object who,int val) {
	message_vision( (this_object())->query("name")+"��$Nһ˦���䣬˵���� ����\n",who);
	return(0);
}

// called when not finish the task
int quest_punish(object who) {
	message_vision( (this_object())->query("name")+"��$Nһ˦���䣬˵���� �汿����ú�ѧѧ������Ҫ����ɣ�\n" ,who);
    who->set("quest",0);
    return(0);
}


