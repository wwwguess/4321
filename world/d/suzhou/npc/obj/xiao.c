//OBJECT: /d/suzhou/npc/obj/xiao.c
//by dwolf                   
//97.11.7

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( GRN"����"NOR, ({ "xiao", "zhu xiao" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
		set("long", MAG"һֻ������Դ�(chui)��"NOR);
                set("value", 1000);
        }
        setup();
}                                                    

void init()
{                            
	add_action("do_chui", "chui");
}

int do_chui(string arg)
{                         
	object me;  
	object obj;
	object ob;
	me = this_player();      
        
  	if ( ((int)me->query("kee") > 200) ||
             ((int)me->query("gin") < 200 ) )
             { 
       		tell_object(me, YEL"���ó�һֻ����������������������Թ��ˡ�����˸��˲��ѡ�\n"NOR); 
		return 1;
	     }
	message_vision(YEL"$N���ش������\n"NOR, me);
        me->add("kee", 1);
	me->receive_damage("gin", 1);   
		   
        if ( random(3) == 0 ) {
                message_vision(RED"$N΢΢һЦ���ó����￪ʼ����������������������̾Ϊ��ֹ��\n"NOR,me);
                me->add("kee", 5);
		me->receive_damage("gin", 5);
                return(1);
        }
        return(1);  
}
  

                 
