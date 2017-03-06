 // que.c ����Ⱥ
#include <ansi.h>
inherit NPC;
//inherit "/std/char/master_yue.c";
inherit F_QUEST;
string ask_me();
void create()
{
        set_name("����Ⱥ",({"yue buqun","yue"}));
        set("nickname", YEL "���ӽ�" NOR);
        set("title",GRN "��ɽ��" NOR + YEL "��ʮ�˴�" NOR+ GRN "����" NOR);
        set("long",
                "��ɽ��������Ⱥ��\n"
                "��������ʮ���꣬�˳ƾ��ӽ����������Ķ������ơ�\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("spi", 31);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("kar", 26);
	set("per", 25);
        set("max_kee", 1200);
        set("max_gin", 800);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
        set("force", 1900);
        set("max_force", 1900);
        set("force_factor", 50);
        set("combat_exp", 1500000);
        set("score", 20000);

        set_skill("force",130);
        set_skill("zixia-shengong", 130);
        set_skill("dodge", 100);
        set_skill("huashan-shenfa", 100);
        set_skill("parry", 110);
        set_skill("sword", 120);
        set_skill("huashan-jianfa",125);
	set_skill("purple", 120);
        set_skill("literate", 100);
        set_skill("cuff", 100);
	set_skill("poyu-quan", 100);
	set_skill("strike", 100);
	set_skill("hunyuan-zhang", 100);

	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

        prepare_skill("cuff", "poyu-quan");
	prepare_skill("sword", "huashan-jianfa");

        create_family("��ɽ��",18,"����");

        set("inquiry", ([
                "�ؼ�" : (: ask_me :),
        ]));

        set("book_count", 1);
        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
}
void attempt_apprentice(object ob)
{
        if((int)ob->query("betrayer")>=10)
        {
                command("say "+RANK_D->query_respect(ob)+"��α������壬���������㡣");
                return;
        }
        else if ((string)ob->query("gender")=="����" && ob->query_skill("pixie-jian")>=50)
        {
                command("say �ҿ����򶫳������ļ�ϸ��");
                return;
        }
        if((string)ob->query("gender")!="����")
          {
           command("say �Ҳ���Ů���ӡ�����㻹�ǰ��ҵ����Ӱɣ�");
           return;
          }
        if((string)ob->query("gender")=="����")
          {
               if ((int)ob->query("max_force") <200) {
                       command("say �һ�ɽ��ԭ�н��ڡ�����֮������������Ϊ�ס�");
                       command("say " + RANK_D->query_respect(ob) +
                               "�Ƿ�Ӧ�ö�����������");
                       return;
               }
               if ((int)ob->query("shen") < 1000) {
                       command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
                       command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                               "�Ƿ����ò�����");
                       return;
               }
           command("say �ðɣ�С�ֵܣ��Ҿ��������ˣ�\n");
           command("say �����Ҫ�Ͷ����ƣ��������壡������Ϊ������������Ϊʦ��
����Ź���ģ�\n");
           command("recruit "+ob->query("id"));
        

           }
}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "��ɽ��")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����ɵľ��鲻�ڴ˴���";
        add("book_count", -1);
        ob = new(__DIR__"book-purple");
        ob->move(this_player());
        return "�ðɣ��Ȿ���������������û�ȥ�ú����С�";
}

void init()
{

        object me, ob;
        mapping fam;


        ::init();
        add_action("give_quest","quest");
        ob = this_player();
        me = this_object();
        if (((int)ob->query("shen")<500 || (int)ob->query("bad") >=3) && ((fam = ob->query("family")) && fam["master_id"] == "yue buqun"))
        {
                command("say ����ɱ�����ˣ����Ž̲��ģ��������������ʦ����\n");
                command("expell "+ ob->query("id"));
        }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                if (this_player()->query("shen")<10000)
                {
                        ob->set("title",GRN "��ɽ��" NOR + YEL +"����" NOR);
                        return;
                }
                else
                {
                        ob->set("title",GRN "��ɽ��" NOR + YEL +"����" NOR);
                        return;
                }

}

void re_rank(object student)
{
                if (this_player()->query("shen")<10000)
                {
                        student->set("title",GRN "��ɽ��" NOR + YEL +"����" NOR);
                        return;
                }
                else
                {
                        student->set("title",GRN "��ɽ��" NOR + YEL +"����" NOR);
                        return;
                }
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

