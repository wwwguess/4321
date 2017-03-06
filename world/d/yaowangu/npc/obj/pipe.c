//OBJECT: /d/fgszhuang/npc/obj/pipe.c
//by dwolf                   
//97.11.7

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( GRN"�����̴�"NOR, ({ "yan dai", "pipe" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
		set("long", YEL"һֻǧ�꺮�����ɵ��̴���������(smoke)��"NOR);
                set("value", 10000);
        }
        setup();
}                                                    

void init()
{                            
	add_action("do_smoke", "smoke");
}

int do_smoke(string arg)
{                         
	object me;  
	object obj;
	object ob;
	me = this_player();      
        
  	if ( ((int)me->query("kee") < 200) ||
             ((int)me->query("gin") > 200 ) )
             { 
       		tell_object(me, YEL"���ó�һֻ�����̴�������������\n"NOR); 
		return 1;
	     }
	message_vision(YEL"$N���������̴���\n"NOR, me);
        me->add("gin", 1);
	me->receive_damage("kee", 1);   
		   
        if ( random(3) == 0 ) {
                message_vision(RED"$N΢΢һЦ���ó��̴���ʼ����������Ľ���ѡ�\n"NOR,me);
                me->add("gin", 5);
		me->receive_damage("kee", 5);
                return(1);
        }
        return(1);  
}
  

                 
