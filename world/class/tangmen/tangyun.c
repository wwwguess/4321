// tangyun.c
// written by tang

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
                    
string ask_me();                                     
void use_poison();
void use_dart();

string *make_msg = ({  
    	HIW"\ͣ��Ƭ�̣�����˵���������ˣ�����������Ե֮�ˣ��Ҿ͸���˵�˰ɡ���\n\n"NOR,    
    	HIG"�����������������֮һ�����곤����������֮�Դ���������������ʱ��\n\n"NOR,
	HIG"̩ɽ֮�ۣ�������һս������ʤ�ܣ�����������÷���������꣬\n\n"NOR,
	HIG"���ֵ����������������ó������������Ųؽ�������Ե֮��ȡ�ã�\n\n"NOR,
	HIG"��ָ��������������ʮ�ꡣ\n\n"NOR,  
	HIY"�ؽ����Կ���ڽ������У���ȥ�����ɣ�һ�п�����컯�ˣ�\n\n"NOR,

});

void create()
{
	set_name("����", ({ "tang yun", "yun", "master" }) );
               set("title",HIR"��������"NOR);
	set("nickname", GRN"�ɻ�����"NOR);
	set("gender", "����");
	set("age", 45);
	set("long","����������������������ʱ���������ڽ�����������������\n"
		"����Ӣ�ۣ�����"+GRN"�ɻ�����"NOR+"�����š���������ţ�ʹ֮��Ϊ\n"
		"������һ�����ɡ�\n"
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
		"���ƽŲ����ƣ������ᵯ��\n",
		"��������һ����������һ�Ŷ���޼��\n",
		(: use_poison :),              
		(: use_dart :),
	 	(: perform_action , "throwing.mantian" :)
	}) );

	create_family("����", 4, "����");

	set_temp("apply/defense", 100);    

	set("inquiry", ([
                	"������" : (: ask_me :),
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
			return CYN"������ô����������أ���\n"NOR;
		}
		else	return "�Ҳ����Ѿ�����������";
	}        
            	return "�������ˣ�����ʮ��ȥ����ѽ��ˡ�";
}
                                                                                        
void make_stage(object who,int stage)
{                                
	tell_object(who,make_msg[stage]);
	if (++stage < sizeof(make_msg) ) {
		call_out( "make_stage", 2, who, stage);
		return;
	}                                                               
	set("sword",query("sword")-1);
	who->set_temp("marks/��1",1);
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
		message_vision( "$N��������һ��������һ����ԭ�������ƵĶ���޼�����ˡ�\n",ob);
		if( !ob->query_condition("tm_poison") )	ob->apply_condition("tm_poison", 20);    
	}
	return ;
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "����")
	{
		command("say ��ֻ�ձ����е��ӣ�"+ RANK_D->query_respect(ob) + "���Ȱݽ����򷽶���");
		return;
	}                                                         
        	if ((string)ob->query("gender")=="����")
	{                                                   
		if (ob->query_skill("tangmen-xinfa")>=80)
		{
			command("say �ðɣ��Ҿ��������ˡ�");
			command("recruit " + ob->query("id"));
        			this_player()->set("class", "legend");
			this_player()->set("title",HIR "����" NOR + GRN +"�������" NOR);
		
		}                       
		else	command("say ��������ķ����������죬�ǲ�����Ҫ��Ŭ��һ�㡣\n");
		return ;
	}
	return ;
}

void init()
{
}
