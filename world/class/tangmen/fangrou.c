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
	set_name("����", ({ "fang rou", "fang" }) );
            	set("title",HIR"��������"NOR);
	set("nickname", YEL"ɢ������"NOR);
	set("gender", "Ů��");
	set("age", 42);
	set("long","�������������������Ƶķ��ˣ�����ʱ��������ͬ��������\n"
		"����"+YEL"ɢ������"NOR+"�����ţ���˵�����Թ�פ�յ���\n");		
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
		"����Ų����ƣ������ת�˼���Ȧ������һЦ��\n",
		"��������һ������з���һ�Ŷ���޼��\n",
		(: use_poison :),              
		(: use_dart :),
		(: heal :),
	 	(: perform_action , "throwing.sanhua" :)
	}) );

	create_family("����", 4, "��������");

	set_temp("apply/defense", 100);
                                                                         
	set("dan",1);
	set("inquiry", ([
                	"פ�յ�" : (: ask_me :),
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
  			if ( who->query("gender")=="Ů��" )
			{
				command("say �� פ�յ�����ʹ������һЩ�������˺����ӣ���\n");
				ob=new("/d/tangmen/obj/zhuyandan");
				ob->move(who);           
				who->set_temp("marks/dan",1);
				return "��������ٳԣ���\n";
			}
                                            return "��ֻ��Ů���Ӳ��ܳ�פ�յ�����\n";
  		}
		return "�Ҳ����Ѿ���������";
	}                                         
            	return "�������ˣ����Ѿ������ˣ�\n";
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

	if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
            	{
		ob->set("kee", ob->query("kee")-40);    
		message_vision( "$N��������һ��������һ����ԭ��������Ķ���޼�����ˡ�\n",ob);
		if( !ob->query_condition("tm_poison") )	ob->apply_condition("tm_poison", 20);    
	}
	return ;
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "����")
	{
		command("say ��ֻ�ձ���Ů���ӣ�"+ RANK_D->query_respect(ob) + "���Ȱݽ����򷽶�\n��");
		return;
	}                                                         
        	if ((string)ob->query("gender")=="Ů��")
	{                                                   
		if (ob->query_skill("sunv-xinfa")>=70)
		{
			command("say �ðɣ��Ҿ��������ˡ�");
			command("recruit " + ob->query("id"));
        			this_player()->set("class", "legend");
			this_player()->set("title",HIR "����" NOR + GRN +"���Ů����" NOR);
		
		}                       
		else	command("say �����Ů�ķ����������죬�ǲ�����Ҫ��Ŭ��һ�㡣\n");
		return ;
	}
	return ;
}

void init()
{
}
