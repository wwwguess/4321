//magic fairy
//by tlang

#include <ansi.h>
inherit NPC;
             
void create()   
{
	set_name(MAG"��������"NOR, ({"magic fairy", "fairy"}));
        set("gender", "Ů��");
	set("age", 20);
	set("per", 50);
	set("long", "�������棬�����ǻã��ò����棬�治�ǻá��ƻ����棬�����ƻ�.�����ǻã�����ʾ֮��\n");
        
	set("combat_exp", 9999999);

	setup();
}

void init()
{       
        object me; 
        me=this_player();

        ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 1, me);    
        add_action("do_regret", "regret");
}
void greeting(object me)
{
        if( !me || environment(me) != environment()) return; 
        command("say ���ҵ����������ʲô��ڵ�����\n"); 
}

int do_regret(string arg)
{                 
        object ob,me;
        me = this_player();

        if( !arg || arg=="" ) 	return 0;     
	
        if( arg=="����" && me->query("mark/����") ) 
        {                             	
                command("sigh");
                command("say ҩ����С���������������ˣ������Ҹ�����Ͼ���ɡ�\n");
                me->add("combat_exp", 10000);
                message_vision("ֻ��һ�������ס$N,Ȼ��ֻ��������˵:�����ˣ�����ʧ�ˣ�����Ҳ�����ˡ�\n",me);
                me->set("mark/�ָ�����", 1);
		me->set("mark/����", 0);
		destruct(this_object()); 
		         return 1;      
        }            
	    if( arg=="����" && me->query("mark/����") ) 
        {                             	
                command("sigh");
                command("say ҩ����С���������˽����ˣ������Ҹ�����Ͼ���ɡ�\n");
                me->add("combat_exp", 15000);
                message_vision("ֻ��һ�������ס$N,Ȼ��ֻ��������˵:�����ˣ�����ʧ�ˣ�����Ҳ�����ˡ�\n",me);
                me->set("mark/�ָ�����", 1);    
		me->set("mark/����", 0);
		destruct(this_object()); 
		         return 1;      
        }            
}
                      

                                           
