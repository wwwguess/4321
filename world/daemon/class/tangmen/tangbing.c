// tangbing.c
// written by tang

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void use_poison();
void use_dart();

void create()
{
	set_name("�Ʊ�", ({ "tang bing", "bing" }) );
               set("title",HIR"���Ż���"NOR);
	set("nickname", RED"���ֽ���"NOR);
	set("gender", "����");
	set("age", 50);
	set("long", "�������������ĸ�磬�������Ż������������ű���������\n");		

	set("attitude", "peaceful");
	set("class", "legend");
	set("apprentice_available", 10);

	set("str", 15 + random(16));
	set("cps", 15 + random(16));
	set("int", 15 + random(16));
	set("cor", 15 + random(16));
	set("con", 15 + random(16));
	set("spi", 15 + random(16));
	set("per", 15 + random(16));
	set("kar", 15 + random(16));
                                        
	set("kee",2000);
        	set("max_kee", 2000);
	set("gin",1000);
        	set("max_gin", 1000);
	set("sen",1000);
	set("max_sen", 1000);
	set("atman", 100);
	set("max_atman", 100);
	set("mana", 100);
	set("max_mana", 100);

	set("force", 3000);
	set("max_force", 3000);
	set("force_factor", 50);

	set("combat_exp", 5000000);
	set("score", 90000);

	set_skill("force", 180);
	set_skill("sword", 180);
	set_skill("throwing", 200);
	set_skill("parry", 180);
	set_skill("dodge", 180);                            
	set_skill("move", 180);
	set_skill("strike",100);
	set_skill("dugong", 200);
	set_skill("literate", 100);

	set_skill("tangmen-xinfa", 180);
	set_skill("tangshi-jian", 180);
	set_skill("mantian-huayu", 200);
	set_skill("taxue-wuhen", 180);
	set_skill("tangmen-duzhang",100);

	map_skill("dodge", "taxue-wuhen");
	map_skill("move", "taxue-wuhen");
	map_skill("force", "tangmen-xinfa");
	map_skill("sword", "tangshi-jian");
	map_skill("parry", "tangshi-jian");   
	map_skill("strike", "tangmen-duzhang");
	map_skill("throwing", "mantian-huayu");

	prepare_skill("strike","tangmen-duzhang");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		"�Ʊ��Ų����ƣ������ᵯ��\n",
		"�Ʊ�����һ����������һ�Ŷ���޼��\n",
		(: use_poison :),              
		(: use_dart :),
	 	(: perform_action , "throwing.mantian" :)
	}) );

	create_family("����", 4, "����");

	set_temp("apply/defense", 100);

	setup();

        	carry_object("/obj/weapon/gangjian")->wield();
        	carry_object("/d/tangmen/obj/jinyi")->wear();
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
		ob->apply_condition("tm_poison", 20);    
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
		message_vision( "$N��������һ��������һ����ԭ�����Ʊ��Ķ���޼�����ˡ�\n",ob);
		if( !ob->query_condition("tm_poison") )	ob->apply_condition("tm_poison", 20);    
	}
	return ;
}

void attempt_apprentice(object ob)
{
	command("say �Ҳ��յ��ӣ�"+ RANK_D->query_respect(ob) + "���ȼ������š�");
	return ;
}

void init()
{
	add_action("do_join", "join");
}

int do_join(string arg)
{
	object who,ob;

	who=this_player();        

	if ( arg!="����" )	return	notify_fail("��Ҫ����ʲô!\n");
	if ((string)who->query("family/family_name") != "����")
	{
		if ( who->query("betrayer")>1 )
			return notify_fail("�㷴���޳��������������㣡\n");

		if( (string)who->query("title")!="��ͨ����" )	who->add("betrayer", 1);

		if ( (string)who->query("gender")=="����")	
		{
			who->set("title",HIR"����"NOR+GRN"�Ҷ�"NOR);   
			who->set("family/family_name","����");  
			ob=present("glove",who);
			if (!ob)
			{
				ob=new("/d/tangmen/obj/glove");
				ob->move(who);  
			}        
			ob=present("baopinang",who);
			if (!ob)
			{
				ob=new("/d/tangmen/obj/baopinang");
				ob->move(who);  
			}          
			message_vision("��ϲ$N�������š�\n", who);  
			return 1;
		}
		if ( (string)who->query("gender")=="Ů��")	
		{                                                       
			who->set("title",HIR"����"NOR+GRN"Ů��"NOR);   
			who->set("family/family_name","����");       
			ob=present("glove",who);
			if (!ob)
			{
				ob=new("/d/tangmen/obj/glove");
				ob->move(who);  
			}        
			ob=present("baopinang",who);
			if (!ob)
			{
				ob=new("/d/tangmen/obj/baopinang");
				ob->move(who);  
			}          
			message_vision("��ϲ$N�������š�\n", who);       
			return 1;                                             
		}           
	}                                                                                                  
	else
	{
		ob=present("glove",who);
		if (!ob)
		{
			ob=new("/d/tangmen/obj/glove");
			ob->move(who);  
			tell_object(who,"����Ū���ˣ��´�С�ĵ㣡\n");
		}        
		ob=present("baopinang",who);
		if (!ob)
		{
			ob=new("/d/tangmen/obj/baopinang");
			ob->move(who);  
			tell_object(who,"��Ƥ��Ū���ˣ��´�С�ĵ㣡\n");	
		}          
		return	notify_fail("�����������ˡ�\n");
	}
}
                                                        
