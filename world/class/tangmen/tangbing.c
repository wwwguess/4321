// tangbing.c
// written by tang

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void use_poison();
void use_dart();

void create()
{
	set_name("唐冰", ({ "tang bing", "bing" }) );
               set("title",HIR"唐门护法"NOR);
	set("nickname", RED"三手剑客"NOR);
	set("gender", "男性");
	set("age", 50);
	set("long", "他是唐门门主的哥哥，现任唐门护法，加入唐门必须问他。\n");		

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
		"唐冰脚步轻移，左手轻弹。\n",
		"唐冰左手一扬，从袖中射出一颗毒蒺藜。\n",
		(: use_poison :),              
		(: use_dart :),
	 	(: perform_action , "throwing.mantian" :)
	}) );

	create_family("唐门", 4, "护法");

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
		tell_object(ob, "你觉得脸上一痒，似乎有什麽东西，伸手一摸却什麽也没有。\n");
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
		message_vision( "$N觉得身上一痒，伸手一摸，原来被唐冰的毒蒺藜打中了。\n",ob);
		if( !ob->query_condition("tm_poison") )	ob->apply_condition("tm_poison", 20);    
	}
	return ;
}

void attempt_apprentice(object ob)
{
	command("say 我不收弟子，"+ RANK_D->query_respect(ob) + "可先加入唐门。");
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

	if ( arg!="唐门" )	return	notify_fail("你要加入什么!\n");
	if ((string)who->query("family/family_name") != "唐门")
	{
		if ( who->query("betrayer")>1 )
			return notify_fail("你反复无常，唐门岂能容你！\n");

		if( (string)who->query("title")!="普通百姓" )	who->add("betrayer", 1);

		if ( (string)who->query("gender")=="男性")	
		{
			who->set("title",HIR"唐门"NOR+GRN"家丁"NOR);   
			who->set("family/family_name","唐门");  
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
			message_vision("恭喜$N加入唐门。\n", who);  
			return 1;
		}
		if ( (string)who->query("gender")=="女性")	
		{                                                       
			who->set("title",HIR"唐门"NOR+GRN"女仆"NOR);   
			who->set("family/family_name","唐门");       
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
			message_vision("恭喜$N加入唐门。\n", who);       
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
			tell_object(who,"手套弄丢了，下次小心点！\n");
		}        
		ob=present("baopinang",who);
		if (!ob)
		{
			ob=new("/d/tangmen/obj/baopinang");
			ob->move(who);  
			tell_object(who,"豹皮囊弄丢了，下次小心点！\n");	
		}          
		return	notify_fail("你已是唐门人。\n");
	}
}
                                                        
