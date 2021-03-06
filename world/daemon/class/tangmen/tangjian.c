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
	set_name("唐剑", ({ "tang jian", "jian" }));
        	set("long",
                "他是唐门门主唐云的大儿子，是唐门未来的门主。\n"
                "相貌英俊，刚满二十岁，看起来踌躇满志。\n");
	set("title",HIR "唐门" NOR + GRN "少门主" NOR);
	set("gender", "男性");
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
		"钥匙"	:(:ask_me:),
			]));	
        	create_family("唐门", 5, "弟子");
        	set("class", "legend");

        	setup();
        	carry_object("/obj/weapon/gangjian")->wield();
        	carry_object("/d/tangmen/obj/jinyi")->wear();
}
                       
string ask_me()
{
	object who;
    	who=this_player();  

	if ( who->query_temp("marks/唐1")==1 )
	{
		who->delete_temp("marks/唐1");
		who->set_temp("marks/唐2",1);
		return CYN"“几天前我将爹爹给的藏剑阁钥匙弄丢了。”\n"NOR;
	}        
            	return "我不知道你在问什么。\n";
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
		message_vision( "$N觉得身上一痒，伸手一摸，原来被唐剑的毒蒺藜打中了。\n",ob);
		if( !ob->query_condition("tm_poison") )	ob->apply_condition("tm_poison", 10);    
	}
	return ;
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "唐门")
	{
		command("say 我只收本门男弟子，"+ RANK_D->query_respect(ob) + "可先加入唐门。\n");
		return;
	}                                                         
        	if ((string)ob->query("gender")=="男性")
	{
		command("say 好吧，我就收下你了。");
		command("recruit " + ob->query("id"));
        		this_player()->set("class", "legend");
		this_player()->set("title",HIR "唐门" NOR + GRN +"六代弟子" NOR);  
	}           	
	return ;
}

void init()
{
}