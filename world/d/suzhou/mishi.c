//ROOM:/d/suzhou/mishi.c
//by dwolf
//97.11.7              

string look_zi();          
#include <ansi.h>
inherit ROOM;          

void create()
{                           
	set("short", RED"����������"NOR);
	set("long", @LONG
        	 �������¹����ɵ�������������ң�������ߺڰ�������ϡ����
�����б��顣ǽ�Ϸ·�����(zi),��֪��дЩʲô���ذ���Щ�ɶ����������ã��·�
�ǿյġ�
LONG
	);                                        
	set("exits", ([
		"up" : __DIR__"whci", 
]));             
	set("objects", ([
		"/d/hangzhou/npc/obj/wmbook3" : 1,    
]));                         
	set("item_desc", ([
		"zi" :  (: look_zi :),
]));
	setup();
}      

string look_zi()
{
	return "�������飬������Ե�ˡ�\n\n ����\n";
}                                     

void init()
{
	add_action("do_dig", "dig");
}


int do_dig(string arg)
{
        object me;
	object ob;
	me = this_player();
        
        if ( !arg || arg != "�ذ�" )
                return notify_fail("��Ҫ��ʲ��?\n");
                       
        if ( ((int)me->query_skill("unarmed") < 50) ) { 
                tell_object(me, "�����̫�ͣ��ڲ�����\n");
                return 1;
        }

        else if( ((int)me->query("kee")<200))
             {tell_object(me, "��������̫��ร�\n");  
              return 1;
             }
 
        me->receive_damage("gin",15);
        me->receive_damage("kee",30);
        message_vision("$N�ó�������Ŀ쵶������������\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("$N��Ȼһ��̤�գ�������ȥ��\n",me); 
		me->move(__DIR__"mishi2");
                tell_room(__DIR__"mishi2", BLK"һ���˴��������������\n"NOR);
		me->receive_damage("kee", 100);
		me->receive_damage("gin", 50); 
	     return(1);
        }
        return(1);
}

