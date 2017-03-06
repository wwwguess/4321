// zhang.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
string ask_me();
void consider();



void create()
{
        set_name("���޼�",({"zhang wuji","zhang"}));
        set("long", "�������ʮ���ꡣ\n");

        set("title",GRN "����" NOR + YEL "����" NOR);
        set("gender", "����");
        set("age", 26);
        set("attitude", "peaceful");
        set("cor", 41);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("per", 27);

        set("max_kee", 4000);
        set("max_gin", 2000);
	set("max_sen", 600);
	set("atman", 600);
	set("max_atman", 600);
	set("mana", 300);
	set("max_mana", 300);
        set("force", 4000);
        set("max_force", 4000);
        set("force_factor", 100);
          set("combat_exp", 5000000);
        set("score", 40000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
      set("inquiry", ([

                "ʥ����" : (: ask_me :),
        ]) );
       set("book_count", 1);


        set_skill("force",190);
        set_skill("jiuyang-shengong", 200);
        set_skill("dodge", 200);
        set_skill("tiyunzong", 180);
        set_skill("parry", 200);
        set_skill("sword", 190);
        set_skill("shenghuo-shengong",200);
        set_skill("literate", 100);
        set_skill("strike", 180);
	set_skill("qiankun-danuoyi", 200);
        set_skill("iron-cloth",200);

        map_skill("strike", "shenghuo-shenggong");
        map_skill("iron-cloth", "jiuyang-shengong");
        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("parry", "qiankun-danuoyi");
        map_skill("sword", "shenghuo-shengong");

        prepare_skill("strike", "shenghuo-shengong");
	prepare_skill("sword", "shenghuo-shengong");
	prepare_skill("parry", "qiankun-danuoyi");

        create_family("����",19,"����");

        setup();

        carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
        carry_object("/d/mingjiao/obj/changpao")->wear();
}

void attempt_apprentice(object ob)
{
	
	if ((string)ob->query("family/family_name")!="����")
	{
		command("say ������ɵ��ӣ��Ҳ������㡣");
		return ;
	}

        if((int)ob->query("betrayer"))
	{
		command("say "+RANK_D->query_respect(ob)+"������ʦ���������塣��
�������㡣\n");
		return;
	}

        if ((int)this_player()->query_int() < 30 )
        {
                command("say ѧϰ�����ؼ�Ҫ�кõ����ԣ�"+RANK_D->query_respect(ob)+"��
�ʲ�����");
                return;
        }
    if ((int)ob->query_skill("jiuyang-shengong", 1) < 50) {
                command("say ����ڹ��ķ���Ϊ������");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ���ھ������϶��µ㹦��");
                return;
        }

        command("say �ðɣ�"+RANK_D->query_respect(ob)+"���Ҿ��������ˣ�\n");
	
        command("recruit "+ob->query("id"));
	ob->set("title", GRN "����" NOR + YEL "����" NOR);

}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
	 switch( random(2) )
        {
            case 0:
	    command("perform parry.yi " + target->query("id"));
	     break;
            case 1:
                command("perform tisha " + target->query("id"));
	     break;
             }

}

string ask_me()
{
        mapping fam;
        object ob;
            if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "����")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
	if((string)this_player()->query("family/master_id") != "zhang wuji")
	return "������̫�ף�ʥ�����˱������֮�������ܸ��㡣";
	
        if (query("book_count") < 1)
                return "�������ˣ����̵�ʥ����ڴ˴���";
        add("book_count", -1);
        ob = new("/d/mingjiao/obj/shenghuo-ling");
        ob->move(this_player());
        return "�ðɣ����ʥ�������û�ȥ�úñ��ܡ�";
}

void init()
{
   add_action("give_quest","quest");
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
	message_vision( (this_object())->query("name")+"��$Nһ˦���䣬˵���� ʲô�������¸���𣿣�\n",who);
	return(0);
}

// called when not finish the task
int quest_punish(object who) {
	message_vision( (this_object())->query("name")+"��$Nһ˦���䣬˵���� �汿����ú�ѧѧ������Ҫ����ɣ�\n" ,who);
    who->set("quest",0);
    return(0);
}

