// fengmof.c     
//write by lysh
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
void create()
{
	set_name("������", ({ "feng tiejiang", "feng", "smith" }) );
	set("gender", "����" );
	set("age", 53);
	set("long", 
"���������ǳ��������������������ˣ�˫�۱��̻�޹���ֺ���ϸ��\n"
"���Ȳзϣ������³���һ�����ȡ�\n");
      
	set("title", RED "�һ���" NOR + GRN +"����" NOR);
        set("gender", "����");
	set("class","ƽ��");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 30);
        set("con", 24);
        set("dex", 28);
	set("per", 20);

        set("max_kee", 300);
        set("max_gin", 260);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
        set("force", 700);
        set("max_force", 700);
        set("force_factor", 20);
	set("combat_exp", 20000);
        set("score", 1000);

        set("chat_chance_combat", 80);

	set_skill("literate", 50);
	set_skill("qimen-bagua", 50);
        set_skill("force", 50);
	set_skill("taohua-force", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("sword", 50);
        set_skill("yuxiao-jian", 50);
	
	set_skill("baguabu", 50);
        set_skill("hand", 50);
        set_skill("lanhua-shou", 50);
        set_skill("strike", 50);
        set_skill("luoying-zhang", 50);

	map_skill("force", "taohua-force");
        map_skill("parry", "lanhua-shou");
        map_skill("sword", "yuxiao-jian");
        map_skill("dodge", "baguabu");
        map_skill("strike", "luoying-zhang");
        map_skill("hand", "lanhua-shou");
	
        prepare_skill("strike", "luoying-zhang");
 	prepare_skill("hand", "lanhua-shou");

        create_family("�һ���", 2, "����");

	set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);

//        set("chat_chance", 50);
//	set("chat_msg_combat", (: add_hammer :));
	set("inquiry", ([
		"name": "С���շ룬�����˶����ҷ�������",
		"here": "������С�˺��ڵ����ӣ�С�˾�ס����ߵ����ӡ�",
		"��ͷ": "��ͷ... ��Ǹ����ͷ�Ѿ�������...",
		"����": "������С������������������ã�һ��ֻҪ������Ǯ��",
		"��"  : 
"Ŷ�����Ǹ���ɽ�������Ŵ�ģ�С�����������£�����û�˷��ǿ������\n"
"�ţ�������ǰ��������ͽ��ɽȥ�ˣ���֪ʲ��ʱ��Ż�������ȡ����",
		"ȡ��": "С��һ��Ҫ���������ŵ����Ų��ܸ�����",
		"��Ĭ��" : "�������������С���Ѿ��þ�û����������...",
		"���Ŷݼ�" : "�Ƕ���Сʱ��ѧ�ģ�ƽʱû�½���ư��ˡ�",
	]) );
	setup();
        carry_object("/obj/weapon/gangjian")->wield();
         set("vendor_goods", ({
                __DIR__"obj/hammer",
        }));
        add_money("coin", 50);
}             
void init()
{               
        
         ::init(); 
	 add_action("give_quest","quest");

}

int accept_object(object who, object ob)
{
	object sword;
	object me=this_player();
	object obj=ob;
        if (!userp(ob) && (string)ob->query("id")=="shouxin") {
	      sword = new(__DIR__"obj/youlong");
              if(!query("yl_trigger")) {
		say(
"������˵������ѽ��䲻���ۣ���Ҳ��С�˵���Ѫ������Ե��������š�\n"
"��������" + sword->query("name") + "������" + who->query("name") + "��\n");
		sword->move(who);
                set("yl_trigger", 1);
              }
           else say("��������Ҳ��̧��˵����Ҫ���Լ���ȥ�á�\n");
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
	return 1;
	}
	else return ::accept_object(who,ob);
}
void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
// void add_hammer()
// {
//	if (this_object()->is_fighting() )
//             carry_object(__DIR__"obj/hammer")->wield();
// }

void attempt_apprentice(object ob)
{        
        if ( (int)this_player()->query("combat_exp")>100) 
         {   command("say ����ֻ���޼ҿɹ�Ĺ¶���");
            return;
          }
        if ( this_player()->query("class")=="bonze")
        {
                command("say ���ɲ��շ��ŵ��ӣ�" + RANK_D->query_respect(ob) + "���ֻ�����������");
                return;
        }
        if ( this_player()->query("class")=="eunach")
        {
                command("say ���ɲ���̫�࣬" + RANK_D->query_respect(ob) + "��ذɡ�");
                return;
        }

	if ((string)ob->query("class") == "taoist")
	{
		command("say ���ɲ��յ�ʿ��"+ RANK_D->query_respect(ob) + "��ذɡ�");
	        return;
	}
        command("say �ðɣ��Ҿ������ʦ��ҩʦ�������ˡ�");
        command("recruit " + ob->query("id"));
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        
        if (ob->query("age")<20)
        {
        	if((string)ob->query("gender")!="Ů��")
		{
                	ob->set("title",RED "�һ���" NOR + GRN +"Сͯ" NOR);
			return;
		}
        	else
		{
                	ob->set("title",RED "�һ���" NOR + GRN +"Ůͯ" NOR);
			return;
		}
        }
        else 
	{
        	if((string)ob->query("gender")!="Ů��")
                {
			ob->set("title",RED "�һ���" NOR + GRN +"�������" NOR);
			return;
		}
	        else
                {
			ob->set("title",RED "�һ���" NOR + GRN +"����Ů����" NOR);
			return;
		}
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
			student->set("title",RED "�һ���" NOR + GRN +"�������" NOR);
			return;
		}
	        else
                {
			student->set("title",RED "�һ���" NOR + GRN +"����Ů����" NOR);
			return;
		}
        }
}

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

