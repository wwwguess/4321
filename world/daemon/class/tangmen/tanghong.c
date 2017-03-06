// tanghong.c
// written by tang

#include <ansi.h>

inherit NPC;

void use_poison();
void use_dart();

void create()
{
	set_name("�ƺ�", ({ "tang hong", "hong" }) );
               set("title",HIR"���Ż���"NOR);  
	set("long", "�������������ĵܵܣ��ָ������Ž�ҩ����ҩ�Ͱ����ķ��š�\n");
	set("nickname", RED"���ֽ���"NOR);
	set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("class", "legend");
                                  
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

	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 50);

	set("combat_exp", 5000000);
	set("score", 90000);

	set_skill("force", 150);
	set_skill("sword", 150);
	set_skill("throwing", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);  
	set_skill("move", 150);                          
	set_skill("strike",100);
	set_skill("literate", 100);

	set_skill("tangmen-xinfa", 150);
	set_skill("tangshi-jian", 150);
	set_skill("mantian-huayu", 150);
	set_skill("taxue-wuhen", 150);
	set_skill("tangmen-duzhang",100);  
	set_skill("dugong",150);

	map_skill("dodge", "taxue-wuhen");
	map_skill("move", "taxue-wuhen");
	map_skill("force", "tangmen-xinfa");
	map_skill("sword", "tangshi-jian");
	map_skill("parry", "tangshi-jian");   
	map_skill("strike", "tangmen-duzhang");
	map_skill("throwing", "mantian-huayu");

	prepare_skill("strike", "tangmen-duzhang");                                                    
                                                                                                                             
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		"�ƺ�Ų����ƣ������ᵯ��\n",
		"�ƺ�����һ����������һ�Ŷ���޼��\n",
		(: use_poison :),              
		(: use_dart :),
	 	(: perform_action , "throwing.mantian" :)
	}) );

	create_family("����", 4, "����");

	set_temp("apply/defense", 100);

	carry_object("/d/tangmen/obj/jinyi")->wear();
	carry_object("/obj/weapon/gangjian")->wield();
	setup();

}

void attempt_apprentice(object ob)
{
	command("say �Ҳ��յ��ӣ�"+ RANK_D->query_respect(ob) + "���ȼ������š�");
	return ;
}

void init()
{
	add_action("do_ask","yao");
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
		message_vision( "$N��������һ��������һ����ԭ�����ƺ�Ķ���޼�����ˡ�\n",ob);
		if( !ob->query_condition("tm_poison") )	ob->apply_condition("tm_poison", 20);    
	}
	return ;
}


int do_ask(string arg)
{
	object who,obj;                                                 
	int i,j;

	who=this_player();        

	if ( (string)who->query("family/family_name")!="����" )	return notify_fail("��Ǳ��ŵ��ӣ��⻰�Ӻ�˵��\n");

	if (arg=="����" || arg=="��ҩ" || arg=="��ҩ")
	{                                                  
		obj=present("baopinang",who);
                             	if (!obj)	return notify_fail("��ı�Ƥ�Ҷ��ˣ�û�ط��ţ�ȥ�����ȥ����һ����\n");
	
		i=who->query("mud_age");
		j=who->query("askthing");
		if( (i-j)>1800 )
		{
               		obj->set("medicine", 10);       
			who->set("askthing", i);
			tell_object(who,"��ҩ�Ѿ�����װ�ڱ�Ƥ��������\n");
			
			if( who->query_skill("dugong")>30 )	
			{
			obj->set("poison", 20);
			tell_object(who,"��ҩ�Ѿ�����װ�ڱ�Ƥ��������\n");
			}
			else	tell_object(who,"��Ķ������������죬���ܸ������Ŷ�ҩ��\n");

			if( who->query_skill("throwing")>30 )	
			{
			obj->set("dart", 20);      
			tell_object(who,"�����Ѿ�����װ�ڱ�Ƥ��������\n");
			}
			else	tell_object(who,"��İ����ַ����������죬���ܸ������Ű�������޼��\n");			
			return 1;
		}
		return notify_fail("�ո����㣬����Ҫ����Сʱ������Ҫ��\n");
	}
	return notify_fail("��Ҫʲô��\n");                                                        
}
                                                                           
