//OBJECT: /d/fgszhuang/npc/obj/chabei.c
//by dwolf                   
//97.11.7

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( RED"��ɲ豭"NOR, ({ "yuci chabei", "chabei" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
		set("long", YEL"һֻǧ�꺮�����ɵĲ豭�����Ժȡ�"NOR);
                set("value", 10000);
        }
        setup();
}                                                    

void init()
{                            
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{                         
	object me;  
	object obj;
	object ob;
	me = this_player();      
        
  	if ( ((int)me->query("kee") > 200) ||
             ((int)me->query("gin") > 200 ) )
             { 
       		tell_object(me, YEL"�����һֻ��ɲ豭������������\n"NOR); 
		return 1;
	     }
	message_vision(YEL"$N���غ��������衣\n"NOR, me);
        me->add("gin", 5);
	me->add("kee", 5);   
		   
        if ( random(3) == 0 ) {
                message_vision(RED"$N΢΢һЦ���ó���ɲ豭��ʼ�ȣ�������Ľ���ѡ�\n"NOR,me);
                me->add("gin", 20);
		me->add("kee", 20);
                return(1);
        }
        return(1);  
}
  

                 
