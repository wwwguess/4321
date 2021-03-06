// tanghong.c
// written by tang

#include <ansi.h>

inherit NPC;

void use_poison();
void use_dart();

void create()
{
	set_name("唐宏", ({ "tang hong", "hong" }) );
               set("title",HIR"唐门护法"NOR);  
	set("long", "他是唐门门主的弟弟，现负责唐门解药、毒药和暗器的发放。\n");
	set("nickname", RED"毒手剑客"NOR);
	set("gender", "男性");
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
		"唐宏脚步轻移，左手轻弹。\n",
		"唐宏左手一扬，从袖中射出一颗毒蒺藜。\n",
		(: use_poison :),              
		(: use_dart :),
	 	(: perform_action , "throwing.mantian" :)
	}) );

	create_family("唐门", 4, "护法");

	set_temp("apply/defense", 100);

	carry_object("/d/tangmen/obj/jinyi")->wear();
	carry_object("/obj/weapon/gangjian")->wield();
	setup();

}

void attempt_apprentice(object ob)
{
	command("say 我不收弟子，"+ RANK_D->query_respect(ob) + "可先加入唐门。");
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
		message_vision( "$N觉得身上一痒，伸手一摸，原来被唐宏的毒蒺藜打中了。\n",ob);
		if( !ob->query_condition("tm_poison") )	ob->apply_condition("tm_poison", 20);    
	}
	return ;
}


int do_ask(string arg)
{
	object who,obj;                                                 
	int i,j;

	who=this_player();        

	if ( (string)who->query("family/family_name")!="唐门" )	return notify_fail("你非本门弟子，这话从何说起。\n");

	if (arg=="暗器" || arg=="解药" || arg=="毒药")
	{                                                  
		obj=present("baopinang",who);
                             	if (!obj)	return notify_fail("你的豹皮囊丢了，没地方放，去大哥那去再领一个。\n");
	
		i=who->query("mud_age");
		j=who->query("askthing");
		if( (i-j)>1800 )
		{
               		obj->set("medicine", 10);       
			who->set("askthing", i);
			tell_object(who,"解药已经给你装在豹皮囊里啦！\n");
			
			if( who->query_skill("dugong")>30 )	
			{
			obj->set("poison", 20);
			tell_object(who,"毒药已经给你装在豹皮囊里啦！\n");
			}
			else	tell_object(who,"你的毒功还不够精熟，不能给你唐门毒药。\n");

			if( who->query_skill("throwing")>30 )	
			{
			obj->set("dart", 20);      
			tell_object(who,"暗器已经给你装在豹皮囊里啦！\n");
			}
			else	tell_object(who,"你的暗器手法还不够精熟，不能给你唐门暗器毒蒺藜。\n");			
			return 1;
		}
		return notify_fail("刚给过你，又来要，半小时后再来要！\n");
	}
	return notify_fail("你要什么？\n");                                                        
}
                                                                           
