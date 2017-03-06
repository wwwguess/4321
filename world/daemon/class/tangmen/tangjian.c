//tangjian.c
//written by tang

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();
void use_poison();
void use_dart();

void create()
{
	set_name("�ƽ�", ({ "tang jian", "jian" }));
        	set("long",
                "���������������ƵĴ���ӣ�������δ����������\n"
                "��òӢ����������ʮ�꣬�����������־��\n");
	set("title",HIR "����" NOR + GRN "������" NOR);
	set("gender", "����");
        	set("age", 20);
        	set("attitude", "friendly");
       	set("shen_type", 1);

	set("str", 15 + random(16));
	set("cps", 15 + random(16));
	set("int", 15 + random(16));
	set("cor", 15 + random(16));
	set("con", 15 + random(16));
	set("spi", 15 + random(16));
	set("per", 15 + random(16));
	set("kar", 15 + random(16));
                                        
	set("kee",1000);
        	set("max_kee", 1000);
	set("gin",600);
        	set("max_gin", 600);
	set("sen",600);
	set("max_sen", 600);
	set("atman", 100);
	set("max_atman", 100);
	set("mana", 100);
	set("max_mana", 100);

	set("chat_chance_combat", 50);
        	set("chat_msg_combat", ({
	 	(: perform_action , "throwing.mantian" :),
		(: use_poison :),
		(: use_dart :),
	        }) );

        	set("force", 1500);
        	set("max_force", 1500);
        	set("force_factor", 40);
          	set("combat_exp", 200000);
        	set("score", 50000);

        	set_skill("force", 100);
        	set_skill("tangmen-xinfa", 100);
	set_skill("move", 100);
        	set_skill("dodge", 100);
        	set_skill("taxue-wuhen", 100);
	set_skill("strike", 100);
        	set_skill("tangmen-duzhang", 100);
        	set_skill("parry", 100);
        	set_skill("sword", 100);
        	set_skill("tangshi-jian", 100);
	set_skill("throwing",100);
	set_skill("mantian-huayu",100);
	set_skill("dugong",100);
               set_skill("literate", 100);

        	map_skill("force", "tangmen-xinfa");
        	map_skill("dodge", "taxue-wuhen");
	map_skill("move", "taxue-wuhen");
	map_skill("strike", "tangmen-duzhang");
        	map_skill("parry", "tangshi-jian");
        	map_skill("sword", "tangshi-jian"); 
	map_skill("throwing", "mantian-huayu");

        	prepare_skill("strike", "tangmen-duzhang");

	set("inquiry",([
		"Կ��"	:(:ask_me:),
			]));	
        	create_family("����", 5, "����");
        	set("class", "legend");

        	setup();
        	carry_object("/obj/weapon/gangjian")->wield();
        	carry_object("/d/tangmen/obj/jinyi")->wear();
}
                       
string ask_me()
{
	object who;
    	who=this_player();  

	if ( who->query_temp("marks/��1")==1 )
	{
		who->delete_temp("marks/��1");
		who->set_temp("marks/��2",1);
		return CYN"������ǰ�ҽ��������Ĳؽ���Կ��Ū���ˡ���\n"NOR;
	}        
            	return "�Ҳ�֪��������ʲô��\n";
}
                            
void use_poison()
{
	object *enemy, ob;
	string msg;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	if( ob->query_condition("tm_poison") ) return;

	if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
            	{
		ob->apply_condition("tm_poison", 10);    
		tell_object(ob, "���������һ�����ƺ���ʲ�ᶫ��������һ��ȴʲ��Ҳû�С�\n");
	}
	return ;
}

void use_dart()
{
	object *enemy, ob;
	string msg;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	if( random(query("combat_exp")) > (int)ob->query("combat_exp")/2 )
            	{
		ob->set("kee", ob->query("kee")-40);    
		message_vision( "$N��������һ��������һ����ԭ�����ƽ��Ķ���޼�����ˡ�\n",ob);
		if( !ob->query_condition("tm_poison") )	ob->apply_condition("tm_poison", 10);    
	}
	return ;
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "����")
	{
		command("say ��ֻ�ձ����е��ӣ�"+ RANK_D->query_respect(ob) + "���ȼ������š�\n");
		return;
	}                                                         
        	if ((string)ob->query("gender")=="����")
	{
		command("say �ðɣ��Ҿ��������ˡ�");
		command("recruit " + ob->query("id"));
        		this_player()->set("class", "legend");
		this_player()->set("title",HIR "����" NOR + GRN +"��������" NOR);  
	}           	
	return ;
}

void init()
{
}