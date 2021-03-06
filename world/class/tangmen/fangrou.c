// fangrou.c
// written by tang

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
                  
string ask_me();
void use_poison();         
void use_dart(); 
void heal();

void create()
{
	set_name("方柔", ({ "fang rou", "fang" }) );
            	set("title",HIR"门主夫人"NOR);
	set("nickname", YEL"散花仙子"NOR);
	set("gender", "女性");
	set("age", 42);
	set("long","她是唐门现任门主唐云的夫人，少年时曾与唐云同闯江湖，\n"
		"博得"+YEL"散花仙子"NOR+"的名号，据说她曾吃过驻颜丹。\n");		
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

	set_skill("force", 150);
	set_skill("sword", 150);
	set_skill("throwing", 180);
	set_skill("parry", 150);
	set_skill("dodge", 160);                  
	set_skill("move", 160);          
	set_skill("strike",100);
	set_skill("literate", 100);
	set_skill("music", 100);
	set_skill("dugong", 180);                                                

	set_skill("sunv-xinfa", 150);
	set_skill("yuenv-jian", 150);
	set_skill("tiannv-sanhua", 180);
	set_skill("taxue-wuhen", 160);
	set_skill("tangmen-duzhang",120);

	map_skill("dodge", "taxue-wuhen");              
	map_skill("move", "taxue-wuhen");
	map_skill("force", "sunv-xinfa");
	map_skill("sword", "yuenv-jian");
	map_skill("parry", "yuenv-jian");   
	map_skill("strike", "tangmen-duzhang");
	map_skill("throwing", "tiannv-sanhua");     

	prepare_skill("strike","tangmen-duzhang");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		"方柔脚步轻移，翩翩地转了几个圈，回眸一笑。\n",
		"方柔左手一扬，从袖中发出一颗毒蒺藜。\n",
		(: use_poison :),              
		(: use_dart :),
		(: heal :),
	 	(: perform_action , "throwing.sanhua" :)
	}) );

	create_family("唐门", 4, "门主夫人");

	set_temp("apply/defense", 100);
                                                                         
	set("dan",1);
	set("inquiry", ([
                	"驻颜丹" : (: ask_me :),
        		]));                                                 

	setup();
        	carry_object("/obj/weapon/gangjian")->wield();
        	carry_object("/d/tangmen/obj/skirt")->wear();

}

string ask_me()
{
	object who,ob;
    	who=this_player();  
	if ( query("dan")>0 )
	{                              
		if ( who->query_temp("marks/dan")!=1 )
		{			
  			if ( who->query("gender")=="女性" )
			{
				command("say “ 驻颜丹可以使你年轻一些，但会伤害脑子！”\n");
				ob=new("/d/tangmen/obj/zhuyandan");
				ob->move(who);           
				who->set_temp("marks/dan",1);
				return "“想清楚再吃！”\n";
			}
                                            return "“只有女孩子才能吃驻颜丹！”\n";
  		}
		return "我不是已经给你了吗？";
	}                                         
            	return "你来晚了，我已经给人了！\n";
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

void use_poison()
{
	object *enemy, ob;
	string msg;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	if( ob->query_condition("tm_poison") ) return;

	if( random(query("combat_exp")) > (int)ob->query("combat_exp")/2 )
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

	if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
            	{
		ob->set("kee", ob->query("kee")-40);    
		message_vision( "$N觉得身上一痒，伸手一摸，原来被方柔的毒蒺藜打中了。\n",ob);
		if( !ob->query_condition("tm_poison") )	ob->apply_condition("tm_poison", 20);    
	}
	return ;
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "唐门")
	{
		command("say 我只收本门女弟子，"+ RANK_D->query_respect(ob) + "可先拜剑儿或方儿\n。");
		return;
	}                                                         
        	if ((string)ob->query("gender")=="女性")
	{                                                   
		if (ob->query_skill("sunv-xinfa")>=70)
		{
			command("say 好吧，我就收下你了。");
			command("recruit " + ob->query("id"));
        			this_player()->set("class", "legend");
			this_player()->set("title",HIR "唐门" NOR + GRN +"五代女弟子" NOR);
		
		}                       
		else	command("say 你的素女心法还不够精熟，是不是需要再努力一点。\n");
		return ;
	}
	return ;
}

void init()
{
}
