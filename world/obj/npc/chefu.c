

#include <ansi.h>

inherit NPC;
inherit F_CLEAN_UP;

                                    
void create()
{
	set_name("����", ({ "huang",  }) );
	set("title", "��վ����");
	set("gender", "����" );
	set("shen_type", 1);
	set("age", 30);
	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);

	set("no_clean_up",1);

	set("long",
		"��������Ц����ĳ��ϰ壬��Ȼ���򲻸ߣ�ȴҲ�������ڡ�\n" );

	set("combat_exp", 5000);
	set("attitude", "peaceful");
	set("chat_chance", 1);
	set("chat_msg", ({
		"����˵��: ��λ�͹٣�����������·�� ?\n",
	}) );

	set("max_kee", 300);
	set("max_gin", 200);
	set("force", 100);
	set("max_force", 100);
	set("jiali", 10);
	set("shen_type", 1);
                              
	set_skill("force", 30); 
	set_skill("unarmed", 30);
        set_skill("dodge", 30);
	set_skill("parry", 30);
	
	setup();
	

	carry_object("d/city/obj/cloth")->wear();
}


int accept_object(object who, object ob)
{	
	if (ob->query("money_id") && ob->value() >= 1000) 
	{
		tell_object(who, "����Ц���е�˵��:���Ե�һ��,�����Ϊ��׼������\n");
		who->set_temp("shangche",1);
		return 1;
	}

	return 0;
}

