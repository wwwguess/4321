// jianqiankai.c ��Ǯ��

#include <ansi.h>

inherit NPC;
                                    
void create()
{
	set_name("��Ǯ��", ({ "jian qian kai", "jian", "qian", "kai" }) );
	set("title", "�䳡��ʦ");
	set("gender", "����" );
	set("shen_type", 1);
	set("age", 40);
	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);

	set("no_clean_up",1);

	set("long",
		"��������Ц������ϰ壬��Ȼ���򲻸ߣ�ȴҲ�������ڡ�\n" );

	set("combat_exp", 50000);
	set("attitude", "peaceful");
	set("chat_chance", 1);
	set("chat_msg", ({
		"��Ǯ��˵��: ��λӢ�ۣ�������������� ?\n",
	}) );

	set("max_kee", 700);
	set("max_gin", 400);
	set("force", 7000);
	set("max_force", 7000);
	set("force_factor", 50);
	set("shen_type", 1);
                              
	set_skill("force", 60); 
	set_skill("unarmed", 100);
        set_skill("dodge", 100);
	set_skill("parry", 100);
	
	setup();
	

//	carry_object("/obj/pink_cloth")->wear();
}


int accept_object(object who, object ob)
{
	if(this_object()->query_temp("����/mark"))
		{command("say �ǳ���Ǹ���䳡���������������\n");
		return 0;
		}
	else
	{
		if (ob->query("money_id") && ob->value() >= 50000) 
		{
//			tell_object(who, "��Ǯ��Ц���У��ã�Ӣ������ݡ�\n");
                         command("say �Ǻǣ��������ˣ���ҵ����ֹͣ��\n");
                         return 0;
			who->set_temp("��Ǯ��/mark",1);
			return 1;
		}
        }
	return 0;
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting())
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
	if(this_object()->query_temp("����/mark"))
		command("say �ǳ���Ǹ���䳡���������������\n");
	return ;
}
