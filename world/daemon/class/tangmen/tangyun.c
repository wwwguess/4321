// tangyun.c
// written by tang

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
                    
string ask_me();                                     
void use_poison();
void use_dart();

string *make_msg = ({  
    	HIW"\停了片刻，唐云说道，“罢了，看来你是有缘之人，我就给你说了吧。”\n\n"NOR,    
    	HIG"长生剑乃是武林神兵之一，当年长生剑客曾仗之以闯荡江湖。余少年时，\n\n"NOR,
	HIG"泰山之巅，余与其一战，不分胜败，遂义结金兰。梅儿出生那年，\n\n"NOR,
	HIG"贾兄弟退隐江湖，将所用长生剑放于唐门藏剑阁，让有缘之人取用，\n\n"NOR,
	HIG"屈指算来，至今已有十年。\n\n"NOR,  
	HIY"藏剑阁的钥匙在剑儿手中，你去找他吧，一切看你的造化了！\n\n"NOR,

});

void create()
{
	set_name("唐云", ({ "tang yun", "yun", "master" }) );
               set("title",HIR"唐门门主"NOR);
	set("nickname", GRN"飞花剑客"NOR);
	set("gender", "男性");
	set("age", 45);
	set("long","他是唐门现任门主。少年时，曾游侠于江湖，以手中银剑会\n"
		"江湖英雄，闯下"+GRN"飞花剑客"NOR+"的名号。后接掌唐门，使之成为\n"
		"川西第一大门派。\n"
		);		
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
	set_skill("fanwen", 100);

	set_skill("tangmen-xinfa", 150);
	set_skill("tangshi-jian", 150);
	set_skill("mantian-huayu", 180);
	set_skill("taxue-wuhen", 160);
	set_skill("tangmen-duzhang",120);
	set_skill("dugong",180);                                                         

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
		"唐云脚步轻移，左手轻弹。\n",
		"唐云左手一扬，从袖中射出一颗毒蒺藜。\n",
		(: use_poison :),              
		(: use_dart :),
	 	(: perform_action , "throwing.mantian" :)
	}) );

	create_family("唐门", 4, "门主");

	set_temp("apply/defense", 100);    

	set("inquiry", ([
                	"长生剑" : (: ask_me :),
        		]));                                                 
	set("sword", 10);

	setup();

        	carry_object("/obj/weapon/gangjian")->wield();
        	carry_object("/d/tangmen/obj/jinyi")->wear();

}                      

string ask_me()
{
	object who;
    	who=this_player();  
	if ( query("sword")>0 )
	{                              
		if ( who->query_temp("marks/sword")!=1 )
		{			
			call_out( "make_stage", 2, who, 0 );
			return CYN"“你怎么问这个问题呢？”\n"NOR;
		}
		else	return "我不是已经告诉你了吗？";
	}        
            	return "你来晚了，已有十人去找这把剑了。";
}
                                                                                        
void make_stage(object who,int stage)
{                                
	tell_object(who,make_msg[stage]);
	if (++stage < sizeof(make_msg) ) {
		call_out( "make_stage", 2, who, stage);
		return;
	}                                                               
	set("sword",query("sword")-1);
	who->set_temp("marks/唐1",1);
	who->set_temp("marks/sword",1);
	return;
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
		message_vision( "$N觉得身上一痒，伸手一摸，原来被唐云的毒蒺藜打中了。\n",ob);
		if( !ob->query_condition("tm_poison") )	ob->apply_condition("tm_poison", 20);    
	}
	return ;
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "唐门")
	{
		command("say 我只收本门男弟子，"+ RANK_D->query_respect(ob) + "可先拜剑儿或方儿。");
		return;
	}                                                         
        	if ((string)ob->query("gender")=="男性")
	{                                                   
		if (ob->query_skill("tangmen-xinfa")>=80)
		{
			command("say 好吧，我就收下你了。");
			command("recruit " + ob->query("id"));
        			this_player()->set("class", "legend");
			this_player()->set("title",HIR "唐门" NOR + GRN +"五代弟子" NOR);
		
		}                       
		else	command("say 你的唐门心法还不够精熟，是不是需要再努力一点。\n");
		return ;
	}
	return ;
}

void init()
{
}
