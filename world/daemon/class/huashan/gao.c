// gao.c

inherit F_MASTER;
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("�߸���", ({ "gao genming", "gao", "genming" }));
        set("title",GRN "��ɽ��" NOR + YEL +"����" NOR);
        set("long",
"�߸�����ĸߴ󣬳��ú��֣���������ò�������\n"
"ͬ�������е��壬�ǻ�ɽ������һ���еĺ��֡�\n");
        set("gender", "����");
        set("age", 27);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);

        set("max_kee", 800);
        set("max_gin", 600);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 20);
        set("combat_exp", 10000);
        set("score", 5000);

        set_skill("force", 40);
        set_skill("huashan-neigong", 40);
        set_skill("dodge", 60);
        set_skill("parry", 50);
        set_skill("sword", 60);
        set_skill("huashan-jianfa", 60);
        set_skill("huashan-shenfa", 50);
        set_skill("strike", 60);
        set_skill("hunyuan-zhang", 60);

        map_skill("force", "huashan-neigong");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
        map_skill("dodge", "huashan-shenfa");
        map_skill("strike", "hunyuan-zhang");

        prepare_skill("strike", "hunyuan-zhang");

        create_family("��ɽ��", 19, "����");

        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();
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
           command("say �Ҳ���Ů���ӡ�"+RANK_D->query_respect(ob)+"���㻹�ǰ��ҵ�ʦ�ðɣ�");
           return;
          }
        if((string)ob->query("gender")=="����")
          {
           command("say �ðɣ�"+RANK_D->query_respect(ob)+"���Ҿ��������ˣ�\n");
           command("recruit "+ob->query("id"));

           }
}

void init()
{

        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        if (((int)ob->query("shen")<=-100 || (int)ob->query("bad") >=3) && ((fam = ob->query("family")) && fam["master_id"] == "gao genming"))
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
                        ob->set("title",GRN "��ɽ��" NOR + YEL +"��ͯ" NOR);
                        return;
                }
                else
                {
                        ob->set("title",GRN "��ɽ��" NOR + YEL +"��ʿ" NOR);
                        return;
                }

}

void re_rank(object student)
{
                if (this_player()->query("age")<20)
                {
                        student->set("title",GRN "��ɽ��" NOR + YEL +"��ͯ" NOR)
;
                        return;
                }
                else
                {
                        student->set("title",GRN "��ɽ��" NOR + YEL +"��ʿ" NOR)
;
                        return;
                }
}
