#include <ansi.h>
// song.c ��Զ��

inherit NPC;
inherit F_MASTER;

string ask_me();
void heal();

void create()
{
        set_name("��Զ��", ({ "song yuanqiao", "song" }));
       set("nickname", RED "�䵱����" NOR);

        set("long",
                "������������Ĵ���ӡ��䵱����֮�׵���Զ�š�\n"
                "��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
                "���������ʮ������ݳ���������⡣�񵭳�ͣ���Ĭ���ԡ�\n");
        set("title",RED "�䵱��" NOR + GRN +"����" NOR);
        set("gender", "����");
        set("age", 61);
        set("attitude", "peaceful");
        set("per", 24);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("kar", 28);

        set("max_kee", 2000);
        set("max_gin", 1500);
        set("force", 2300);
        set("max_force", 2300);
        set("force_factor", 50);
        set("combat_exp", 2700000);
        set("score", 30000);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.zhen" :),
                (: exert_function , "powerup" :)
        }) );

        set_skill("force", 160);
        set_skill("taiji-shengong",150);
	set_skill("move", 150);
        set_skill("dodge", 150);
        set_skill("tiyunzong", 150);
        set_skill("cuff", 140);
        set_skill("taiji-quan", 140);
        set_skill("parry", 150);
        set_skill("sword", 150);
      set_skill("taiji-jian", 150);
      set_skill("literate", 100);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
           map_skill("cuff", "taiji-quan");
      map_skill("parry", "taiji-jian");
      map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("�䵱��", 2, "����");

        set("inquiry", ([
                "�ؼ�" : (: ask_me :),
        ]));

        set("book_count", 1);

        setup();
        carry_object("/obj/weapon/gangjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "�䵱��")
	{
		command("say ��ֻ�ձ��ŵ��ӣ�"+ RANK_D->query_respect(ob) + "���Ȱݹ���ʦֶ");
		return;
	}
        command("say �ðɣ�ƶ�����������ˡ�");
        command("recruit " + ob->query("id"));
        this_player()->set("class", "taoist");
        if((string)this_player()->query("gender")!="Ů��")
                this_player()->set("title",RED "�䵱��" NOR + GRN +"����" NOR);
        else
	        this_player()->set("title",RED "�䵱��" NOR + GRN +"Ů����" NOR);
}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";
        add("book_count", -1);
        ob = new(__DIR__"force_book");
        ob->move(this_player());
        return "�ðɣ��Ȿ��̫��ʮ��ʽ�����û�ȥ�ú����С�";
}

void init()
{

        object ob;
        mapping fam;

        ::init();

        ob = this_player();
        if ( (int)ob->query("bellicosity") >200 && ((fam = ob->query("family")) && fam["master_id"] == "song yuanqiao"))
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
