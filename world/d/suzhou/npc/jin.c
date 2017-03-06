//NPC:/d/suzhou/npc/jin.c
//by dwolf
//97.11.5
         
#include <ansi.h>
inherit NPC;            

string ask_me();

void create()
{
	set_name(HIW"��ӹ"NOR, ({ "jin yong", "jin" }));
	set("long", "����������Ϊ������һ��С˵�ң��������������mud��\n�����д��С˵�� �����Ϸ·����������ܡ�\n");
	set("gender", "����");
	set("per", 33);      
	set("int", 50);
        set("age",45);
    
	set_skill("literate", 300);
	set_skill("leadership", 300);

	set_skill("iron-cloth",800);
	set_skill("unarmed", 500);
	set_skill("dodge", 500);
	set_skill("parry", 500);
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 300);
	set_temp("apply/damage", 150);

	set("combat_exp", 10000000);
	set("shen_type", 10);        
	set("inquiry", ([
		"С˵" : (: ask_me :),	
	]));   
	add("count", 1);
	setup();
        
	add_money("gold", 10);
	carry_object(__DIR__"obj/jchmap");
}                                   

string ask_me()
{
	return command("haha") + "�ҵ�С˵���͸���֪�������ˡ�������뿴������ȥ�����Ƕ���";
}                             


int recognize_apprentice(object ob)
{
	if (ob->query("family/family_name")=="��͢")
		return 1;
	if (!(int)ob->query_temp("mark/��"))
		return 0; 
	ob->add_temp("mark/��", -1);
	return 1;
}                   



int accept_object(object who, object ob)
{
/*  lock this func dao 971206 
	if (!(int)who->query_temp("mark/��"))
		who->set_temp("mark/��", 0);
	if (ob->query("money_id") && ob->value() >= 1000) {
		message_vision("��ӹͬ��ָ��$NһЩ����д�ֵ����⡣\n", who);
		who->add_temp("mark/��", ob->value() / 50);
		return 1;
	}
*/
	return 0;
}      

void init()
{
	add_action("give_talk", "talk"); 
	add_action("do_wonder", "wonder");
	::init();
}

int give_talk()
{       
        mapping fam;
        object me;
        me = this_player();

        if ((int)me->query_skill("literate") < 100)  
                return command(RED"say С�ֵ�֪ʶ̫ƶ�����Ϸ�Ҳ�޷�Ϊ�����Ǳ�ܣ��Ǻ�.\n"NOR); 
        
        if (query("count") < 1)
                return command("sigh");
        
        add("count", -1);

        me->add("potential", 50);
        write(YEL"��ͽ���������̸�������Ǳ������ˡ�\n"NOR);
        return 1;
}

int do_wonder(string arg)
{                 
	object ob,me;
	me = this_player();

	if( !arg || arg=="" ) return 0;    
	
	if (query("count") < 1)
                return command("?");
        
        add("count", -1);

	if( arg=="����ȵ�"
	||  arg=="�����") 
	{
		command("haha");
		message("vision", RED"��ӹЦ�Ǻǵ��ó�һ�������㡣\n"NOR, me);
		ob = new("/d/suzhou/npc/obj/guangdie");
		ob ->move(me);

		return 1;      
	}
}
