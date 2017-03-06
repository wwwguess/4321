// linghu.c �����
#include <ansi.h>

inherit NPC;
int ask_lingshan();
int ask_feng();
void create()
{
        set_name("�����",({"linghu chong","linghu","chong"}));
                set("long",
                "��ɽ������������Ⱥ�Ĵ���ӣ�\n"
                "�������ʮ���ꡣ\n");
        set("title",GRN "��ɽ��" NOR + YEL +"����" NOR);
        set("gender", "����");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        set("max_kee", 800);
        set("max_gin", 500);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 50);
        set("combat_exp", 50000);
        set("score", 10000);
        set_skill("force",80);
        set_skill("huashan-neigong", 80);
        set_skill("dodge", 80);
        set_skill("huashan-shenfa", 80);
        set_skill("huashan-jianfa", 60);
        set_skill("parry", 80);
        set_skill("sword", 80);
        set_skill("dugu-jiujian",60);
        set_skill("literate", 80);
        set_skill("cuff", 90);
	set_skill("poyu-quan", 90);

	map_skill("cuff", "poyu-quan");
        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "dugu-jiujian");
        map_skill("sword", "dugu-jiujian");

        prepare_skill("cuff", "poyu-quan");

        create_family("��ɽ��",19,"����");

        set("inquiry", ([
                "�ﲮ��" : "��Ҫ�Ҹ�����ɽȥ�����ա�\n",
                "����ɺ" : (: ask_lingshan :),
                "��̫ʦ��" : (: ask_feng :),
        ]) );
        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/bluerobe")->wear();
}
int ask_lingshan()
{ mapping myfam;
        if (!(myfam = this_player()->query("family"))
            || myfam["family_name"] != "��ɽ��")
   {
      say("�����˵��������Сʦ�ø�ʲô��\n");
      return 1;
   }
  else
   {
      say("�����˵�������ҵ�Сʦ��ѽ������ô�᲻֪���أ�\n");
        set("chat_chance", 10);
        set("chat_msg", ({
        "������ͷ��������˵��Сʦ���Ѿ�����û���ˡ�\n",
        "������ͷ��������˵��Сʦ��֪����ѧ�˷�̫ʦ��Ľ���Ӧ�����Ҹ��˰ɡ�\n",
        "������ͷ��������˵��Сʦ�������ֺ���ƽ֮��һ��ɡ��ȣ�\n",
        }) );
      this_player()->set_temp("marks/ɺ1", 1);
    return 1;
   }
}

int ask_feng()
{
  if ((int)this_player()->query_temp("marks/ɺ1")) {
     say("�����˵����̫ʦ����ɽ���У�����ƽʱ��Ը����ɽ���ӡ�\n");
     this_player()->set_temp("marks/��1", 1);
     return 1;
  }
  else {
     say("�����˵����̫ʦ����ǰ�����ˣ������Ӷ��꣬û��֪���������\n");
     return 1;
  }
}
