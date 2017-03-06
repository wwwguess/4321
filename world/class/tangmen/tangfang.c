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
	set_name("�Ʒ�", ({ "tang fang", "fang" }));
        	set("long",
                "�������������ƵĴ�Ů����\n");
	set("title",HIR "����" NOR + GRN "��С��" NOR);
	set("gender", "Ů��");
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

        	create_family("����", 5, "Ů����");
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
		message_vision( "$N��������һ��������һ����ԭ�����Ʒ��Ķ���޼�����ˡ�\n",ob);
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
	if ((string)ob->query("family/family_name") != "����")
	{
		command("say ��ֻ�ձ���Ů���ӣ�"+ RANK_D->query_respect(ob) + "���ȼ������š�\n");
		return;
	}                                                         
        	if ((string)ob->query("gender")=="Ů��")
	{
		command("say �ðɣ��Ҿ��������ˡ�");
		command("recruit " + ob->query("id"));
        		this_player()->set("class", "legend");
		this_player()->set("title",HIR "����" NOR + GRN +"����Ů����" NOR);
	}
	return ;
}

void init()
{
}