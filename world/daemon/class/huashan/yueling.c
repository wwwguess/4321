// yueling.c ����ɺ
// 2/15/98 rewrite by solor
#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int ask_linghu();
int ask_siguo();

void create()
{
        set_name("����ɺ",({"yue lingshan","lingshan","yue"}));
        set("title",GRN "��ɽ��" NOR + YEL +"Ů����" NOR);
        set("long",
                "��ɽ����������Ⱥ�İ�Ů��\n"
                "��������ʮ���꣬��ò�������䲻�Ǿ������ˣ�Ҳ����һ������֮����\n");
        set("gender", "Ů��");
        set("age", 19);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 18);
        set("int", 22);
        set("con", 26);
        set("dex", 26);
	set("per", 22);

        set("max_kee",  500);
        set("max_gin", 300);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 20);
        set("combat_exp", 10000);
        set("score", 5000);

        set_skill("force", 60);
        set_skill("huashan-neigong", 40);
        set_skill("dodge", 60);
        set_skill("huashan-shenfa", 60);
        set_skill("parry", 55);
        set_skill("sword", 60);
        set_skill("huashan-jianfa", 45);
        set_skill("strike", 50);
        set_skill("hunyuan-zhang", 50);

        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "huashan-neigong");
	map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

        prepare_skill("strike", "hunyuan-zhang");

        set("chat_chance", 10);
        set("chat_msg", ({
          "����ɺ��ͷ��������˵����ʦ�����ڲ�֪��ô���ˣ�\n",
	"����ɺ��½����˵����ʦ�֣����Ǹ�ȥ����ʦ���ͷ��˰ɣ�\n",
        }) );
        create_family("��ɽ��" , 19, "����");
        set("inquiry", ([
                "����Ⱥ" : "����ɺ˵�������˼����ҵĸ��ס�\n",
                "������" : "����ɺ˵�������˼����ҵ�ĸ�ס�\n",
                "�����" : (: ask_linghu :),
                "˼����" : (: ask_siguo :),
        ]) );



        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/greenrobe")->wear();
}
int ask_linghu()
{   object ob;
   //mapping myfam;
  //      if (!(myfam = this_player()->query("family"))
  //          || myfam["family_name"] != "��ɽ��")
   ob = this_player();
   if (ob->query("kar") > 28) 
   {
      say("����ɺ˵�������ҵĴ�ʦ�֣���������˼����˼����\n");
      this_player()->set_temp("marks/��1", 1);
    return 1;    
   }
    if ( random(3)>1 ) 
   {
      say("����ɺ˵�������ҵĴ�ʦ�֣���������ʲô��\n");
      return 1;
   }
  else
   {
      say("����ɺ˵�������ҵĴ�ʦ�֣���������˼����˼����\n");
      this_player()->set_temp("marks/��1", 1);
    return 1;
   }
}

int ask_siguo()
{
  if ((int)this_player()->query_temp("marks/��1")) {
     say("����ɺ˵��˼�����ڻ�ɽ��ɽ�������䳡��������С·����ͨ��˼���¡�\n");
     this_player()->set_temp("marks/˼1", 1);
     return 1;
  }
  else {
     say("����ɺ˵��˼�����ǻ�ɽ�صأ�����ô֪���ģ�\n");
     return 1;
  }
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
        if((string)ob->query("gender")=="Ů��")
          {
        command("say �ðɣ�"+RANK_D->query_respect(ob)+"���Ҿ��������ˣ�");
        command("recruit "+ob->query("id"));

           }
        else {
          command("say �Ҳ����е��ӡ�"+RANK_D->query_respect(ob)+"�㻹��ȥ����ʦ�ְɣ�\n");
            };
}

void init()
{

        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        if (((int)ob->query("shen")<=-100 || (int)ob->query("bad") >=3) && ((fam = ob->query("family")) && fam["master_id"] == "yue lingshan"))
        {
                command("say ����ɱ�����ˣ����Ž̲��ģ��������������ʦ����\n");
		ob->set("bad", 0);
                command("expell "+ ob->query("id"));
        }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                if (this_player()->query("age")<20)
                {
                        ob->set("title",GRN "��ɽ��" NOR + YEL +"Ů��ͯ" NOR);
                        return;
                }
                else
                {
                        ob->set("title",GRN "��ɽ��" NOR + YEL +"Ů��ʿ" NOR);
                        return;
                }

}

void re_rank(object student)
{
                if (this_player()->query("age")<20)
                {
                        student->set("title",GRN "��ɽ��" NOR + YEL +"Ů��ͯ" NOR);
                        return;
                }
                else
                {
                        student->set("title",GRN "��ɽ��" NOR + YEL +"Ů��ʿ" NOR);
                        return;
                }
}
