#include <ansi.h>
// guxu.c ����

inherit NPC;
inherit F_MASTER;

string ask_me();
void heal();

void create()
{
        set_name("�������", ({ "guxu daozhang", "guxu" }));
        set("long",
                "�����������۵ĵ��ӹ��������\n"
                "��������ʮ�꣬�����䵱�ɵ����¡�\n");
       set("title",RED "�䵱��" NOR + GRN +"����" NOR);
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_kee", 1000);
        set("max_gin", 800);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 30);
        set("combat_exp", 60000);
        set("score", 8000);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set_skill("force", 60);
        set_skill("taiji-shengong", 40);
        set_skill("dodge", 60);
        set_skill("tiyunzong", 40);
        set_skill("cuff", 60);
        set_skill("taiji-quan", 50);
	set_skill("move", 40);
//      set_skill("taiji-quan", 60);
        set_skill("parry", 60);
        set_skill("sword", 60);
        set_skill("taiji-jian", 40);
        set_skill("taoism", 60);
//      set_skill("literate", 80);

        map_skill("force", "taiji-shengong");
        map_skill("cuff", "taiji-quan");
        map_skill("dodge", "tiyunzong");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("�䵱��", 3, "����");
        set("class", "taoist");

        set("inquiry",
                ([
                        "���¾�" : (: ask_me :),
                ]));

        set("book_count", 1);

        setup();
        carry_object("/d/wudang/obj/greyrobe")->wear();
        carry_object("/obj/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{

        if ( this_player()->query("class")=="bonze")
        {
                command("say ���ɲ��շ��ŵ��ӣ�" + RANK_D->query_respect(ob) + "���ֻ�����������");
                return;
        }
        if ( this_player()->query("class")=="eunach")
        {
                command("say ���ɲ���̫�࣬" + RANK_D->query_respect(ob) + "���ɡ�");
                return;
        }

	if ((string)ob->query("class") != "taoist")
	{
		command("say ����ֻ�յ�ʿ��"+ RANK_D->query_respect(ob) + "�Ƿ�Ը���������塣");
		command("say ���������ˡ��������(decide)��");
	       	ob->set_temp("prepare/taoist", 1);
	        return;
	}
        if ((int)ob->query("shen") < 0) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ�ƶ�����������ˡ�");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "�䵱��")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����ɵĵ����澭���ڴ˴���";
        add("book_count", -1);
        ob = new("/d/wudang/obj/daodejing-ii");
        ob->move(this_player());
        return "�ðɣ��Ȿ�����¾������û�ȥ�ú����С�";
}

void init()
{

        object ob;
        mapping fam;

        add_action("do_decide", "decide");

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") <=-100 && ((fam = ob->query("family")) && fam["master_id"] == "guxu daozhang"))
	{
		command("say ����ɱ��Խ����������Ϊ���������������ʦ����\n");
		command("expell "+ ob->query("id"));
	}
}		


int do_decide()
{

	object ob=this_player();
        if( !this_player()->query_temp("prepare/taoist") )
                return 0;
	
        this_player()->delete_temp("prepare/taoist");

        if ((int)ob->query("shen") < 0) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return 0;
        }
   
	command("say �ðɣ�ƶ�����������ˡ�");
	command("say ������Ѿ���������ӣ��Ժ����¿�Ҫ�ú����ˣ����������޷����㡣");
	command("recruit " + ob->query("id"));
	return 1;
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
		command("enforce 30");
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

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "taoist");
        if (ob->query("age")<20)
        {
        	if((string)ob->query("gender")!="Ů��")
		{
                	ob->set("title",RED "�䵱��" NOR + GRN +"��ͯ" NOR);
			return;
		}
        	else
		{
                	ob->set("title",RED "�䵱��" NOR + GRN +"С����" NOR);
			return;
		}
        }
        else 
	{
        	if((string)ob->query("gender")!="Ů��")
                {
			ob->set("title",RED "�䵱��" NOR + GRN +"��ʿ" NOR);
			return;
		}
	        else
                {
			ob->set("title",RED "�䵱��" NOR + GRN +"����" NOR);
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
                	student->set("title",RED "�䵱��" NOR + GRN +"��ͯ" NOR);
			return;
		}
        	else
		{
                	student->set("title",RED "�䵱��" NOR + GRN +"С����" NOR);
			return;
		}
        }
        else 
	{
        	if((string)student->query("gender")!="Ů��")
                {
			student->set("title",RED "�䵱��" NOR + GRN +"��ʿ" NOR);
			return;
		}
	        else
                {
			student->set("title",RED "�䵱��" NOR + GRN +"����" NOR);
			return;
		}
        }
}
