// sample master.c code
// xiake island master.c
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
void consider();

void create()
{
	set_name("���߹�", ({"hong qigong", "hong", "qigong"}));
        set("nickname", GRN "��ָ��ؤ" NOR);
        set("title",MAG "ؤ��" NOR + YEL "��ʮ�ߴ�" NOR+ MAG "����" NOR);
	set("gender", "����");
	set("age", 75);
	set("long", 
		"������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

	set("chat_chance", 1);
	set("chat_msg", ({
		"���߹�̾�˿�����������������ʱ���ٳԵ��ض����ġ��л�������������\n",
		"���߹�˵�������׻�˵�����ڽ��ϡ��������Ͻл��ص��������ݿ�������\n",
		"���߹��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n",
//		(: random_move :),
	}));
//	set("inquiry", ([
//		"������" : "����������������\n",
//		"ؤ��" : "����������������\n",
//		"��ʦ" : "�����ȥ�����ŵ��Ұ��ܶ��³�нš�\n",
//	]));
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :),
                (: exert_function, "powerup" :),
                (: perform_action, "staff.chan" :)
        }) );

	set("kee", 1000);
	set("max_kee", 1000);
	set("gin", 300);
	set("max_gin", 300);
	set("sen", 300);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman",300);
	set("force", 3000);
	set("max_force", 2000);
	set("mana", 300);
	set("max_mana", 300);
	set("force_factor", 300);
        set("combat_exp",2000000);
	set("score", 200000);
	set("shen",1000000);
	 
	set_skill("force", 150);             // �����ڹ�
	set_skill("huntian-qigong", 150);    // ��������
	set_skill("strike", 150);
	set_skill("xianglong-zhang", 150);   // ����ʮ����
	set_skill("dodge", 150);      	     // ��������
	set_skill("xiaoyaoyou", 150);        // ��ң��
	set_skill("parry", 150);             // �����м�
	set_skill("staff", 150);             // ��������
	set_skill("dagou-bang", 150);        // �򹷰���
	set_skill("begging", 100);           // �л�����
	set_skill("checking", 100);          // ����;˵
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");

/*	prepare_skill("strike", "xianglong-zhang");*/
	
	create_family("ؤ��", 17, "����");
	setup();
	
	carry_object(__DIR__"yuzhu_zhang");
	carry_object(__DIR__"jiaohuaji");
}

void attempt_apprentice(object ob)
{
        mapping fam;
        if ((string)ob->query("family/family_name")!="ؤ��")
        {
		command("say ����ؤ����Ҫһ��һ������"+ RANK_D->query_respect(ob)+ "��Ҫ��һ����������");
                return;
        }
        if (ob->query("dai")<9)
        {
               	command("say " + RANK_D->query_respect(ob) + "�Ĵ������������ܰ��ұ���");
                return;
        }
        if (ob->query("dai")== 9 )
        {
        if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20) {
                command("say ���л�����Ҫ�ܳԿ����ͣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ��л��ӣ�");
                return;
        }
//      if ((string)ob->query("family/family_name") != "" &&
//          (string)ob->query("family/family_name") != "ؤ��") {
//              command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α��������Ͻл��أ�");
//              return;
//      }
        //command("say " + RANK_D->query_respect(ob) + "��������������ֻ��ϧ�Ͻл�����û������ͽ����");
        command("recruit " + ob->query("id"));
        this_player()->set("title",MAG "ؤ��" NOR + YEL +"�Ŵ�" NOR + MAG "����" NOR);
}

}

int accept_object(object who, object ob)
{

	object me=this_player();
	mapping myfam;
        if (ob->query("food_supply") <= 0)
                return 0;
        if ((string)ob->query("name") != "�л���") {
                command("say �Ͻл���" + (string)ob->query("name") + "ûʲô��Ȥ����");
                return 0;
        }
        if (query("food") >= max_food_capacity() - ob->query("food_supply")) {
                command("say �Ͻл����ڱ��úܡ�");
                return 0;
        }
        command("say ����������������ԵĽл���ѽ��");
        command("eat ji");
        if (!(myfam = this_player()->query("family")) || myfam["family_name"] == "ؤ��" )
        {       
		command("say ��Ȼ�����Т˳���Ҿͽ������С�������������");
                if (me->query_skill("xianglong-zhang", 1) >= 100)
                {
                        say("�����˺��߹��Ľ��⣬ѧ������һ�С�\n");
                        me->set("leiting",1);
                        return 1;
                }
                else
                {
                        say("������Ľ���ʮ���Ƶȼ��������Ժ��߹��Ľ���û��������\n");
                        return 1;
                }
        }
        else
        {       command("say �ҿ�û��������ѽ");
                return 1;
        }
        return 1;
}
void consider()
{
        int i, flag = 0;
        object *enemy;

        enemy = query_enemy() - ({ 0 });
        for(i=0; i<sizeof(enemy); i++) {
                if( !living(enemy[i]) ) continue;
                if( enemy[i]->query_temp("weapon") ) {
                        flag++;
                        if(     !query_temp("weapon") ) {
                                say(RED "\n���߹�˵��������Ȼ" + RANK_D->query_respect(enemy[i]) + "��Ȼʹ���У����¿��ֽ���δ�ⲻ������\n\n" NOR);
                                command("wield yuzhu zhang");
                                command("say ���аɣ�");
                                break;
                        }
                }
        }
        if( !flag && query_temp("weapon") ) {
                if( sizeof(enemy) > 1 )
                        say(RED "\n���߹�˵��������... ��Ȼ" + chinese_number(sizeof(enemy)) + "λ���ǿ��֣����������㣡\n\n��" NOR);
                else
                        say(RED "\n���߹�˵��������Ȼ" + RANK_D->query_respect(enemy[0]) + "��ʹ���У�������Ȼ���㣡\n\n��" NOR);
                command("unwield yuzhu zhang");
        }
}

/*void init()
{
  add_action("give_quest","quest");
}*/

void init()
{
	::init();
        add_action("give_quest", "quest");
}

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

