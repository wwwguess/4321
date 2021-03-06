//tangfang.c
//written by tang

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void heal();     
void use_poison();
void use_dart();

void create()
{
	set_name("唐方", ({ "tang fang", "fang" }));
        	set("long",
                "她唐门门主唐云的大女儿。\n");
	set("title",HIR "唐门" NOR + GRN "大小姐" NOR);
	set("gender", "女性");
        	set("age", 18);
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

	set("chat_chance_combat", 100);
        	set("chat_msg_combat", ({
	 	(: perform_action , "throwing.sanhua" :),
		(: use_poison :),
		(: use_dart :),
		(: heal :),
	        }) );

        	set("force", 1000);
        	set("max_force", 1000);
        	set("force_factor", 30);
          	set("combat_exp", 200000);
        	set("score", 50000);

        	set_skill("force", 100);
        	set_skill("sunv-xinfa", 100);
	set_skill("move", 100);
        	set_skill("dodge", 100);
        	set_skill("taxue-wuhen", 100);
	set_skill("strike", 100);
        	set_skill("tangmen-duzhang", 100);
        	set_skill("parry", 100);         
	set_skill("dugong", 100);
        	set_skill("sword", 100);
        	set_skill("yuenv-jian", 100);
	set_skill("throwing",100);
	set_skill("tiannv-sanhua",100);
               set_skill("literate", 100);

        	map_skill("force", "sunv-xinfa");
        	map_skill("dodge", "taxue-wuhen");        
	map_skill("move", "taxue-wuhen");
	map_skill("strike", "tangmen-duzhang");
        	map_skill("parry", "yuenv-jian");
        	map_skill("sword", "yuenv-jian"); 
	map_skill("throwing", "tiannv-sanhua");

        	prepare_skill("strike", "tangmen-duzhang");

        	create_family("唐门", 5, "女弟子");
        	set("class", "legend");

        	setup();
        	carry_object("/obj/weapon/gangjian")->wield();
        	carry_object("/d/tangmen/obj/skirt")->wear();
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
		message_vision( "$N觉得身上一痒，伸手一摸，原来被唐方的毒蒺藜打中了。\n",ob);
		if( !ob->query_condition("tm_poison") )	ob->apply_condition("tm_poison", 10);    	
	}
	return ;
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

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "唐门")
	{
		command("say 我只收本门女弟子，"+ RANK_D->query_respect(ob) + "可先加入唐门。\n");
		return;
	}                                                         
        	if ((string)ob->query("gender")=="女性")
	{
		command("say 好吧，我就收下你了。");
		command("recruit " + ob->query("id"));
        		this_player()->set("class", "legend");
		this_player()->set("title",HIR "唐门" NOR + GRN +"三代女弟子" NOR);
	}
	return ;
}

void init()
{
}