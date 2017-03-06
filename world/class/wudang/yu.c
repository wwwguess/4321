#include <ansi.h>
// yu.c ������

inherit NPC;
inherit F_MASTER;

void heal();
void create()
{
        set_name("������", ({ "yu lianzhou", "yu" }));
       set("nickname", RED "�䵱����" NOR);
        set("long",
                "������������Ķ����������ۡ�\n"
                "��������ʮ�꣬��Ŀ��࣬�������ء�\n"
                "�����䵱�����������ڶ�������ȴ�����\n");
        set("title",RED "�䵱��" NOR + GRN +"����" NOR);
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_kee", 1500);
        set("max_gin", 800);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 50);
        set("combat_exp", 200000);
        set("score", 80000);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set_skill("force", 100);
        set_skill("taiji-shengong", 60);
        set_skill("dodge", 100);
        set_skill("tiyunzong", 80);
           set_skill("cuff", 80);
        set_skill("taiji-quan", 60);
	set_skill("move", 70);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("taiji-jian", 80);
//      set_skill("taoism", 80);
//      set_skill("literate", 50);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
             map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("�䵱��", 2, "����");

        setup();
       carry_object("/obj/weapon/gangjian")->wield();
       carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "�䵱��")
	{
		command("say ��ֻ�ձ��ŵ��ӣ�"+ RANK_D->query_respect(ob) + "���Ȱ���ͽ����");
		return;
	}
        if ((int)ob->query("shen") <10000) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say " + RANK_D->query_respect(ob) + "��������" +
                        "��������֮�£���һ�����㡣");
                return;
        }
        command("say �ðɣ���Ȼ" + RANK_D->query_respect(ob) + "Ҳ��" +
                "�ұ����ˣ������������ɡ�");
        command("recruit " + ob->query("id"));
        this_player()->set("class", "taoist");
        if((string)this_player()->query("gender")!="Ů��")
                this_player()->set("title",RED "�䵱��" NOR + GRN +"����" NOR);
        else
	        this_player()->set("title",RED "�䵱��" NOR + GRN +"Ů����" NOR);
}

void init()
{

        object ob;
        mapping fam;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") <=0 && ((fam = ob->query("family")) && fam["master_id"] == "yu lianzhou"))
	{
		command("say ����ɱ��Խ����������Ϊ���������������ʦ����\n");
		command("expell "+ ob->query("id"));
	}
}		

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
		command("enforce 50");
                return;
        }

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}
