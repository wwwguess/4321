//ROOM:/d/suzhou/shuidi.c
//by dwolf
//97.11.8 
         
#include <ansi.h>
inherit ROOM;    

void create()
{                           
	set("short", RED"�ɻ���ˮ��"NOR);
	set("long", @LONG
   	 �������ɻ���ˮ�棬�������ڼ��������⣬����û�����Եĳ�·��
�����رߵ�С�����ƺ�������(climb)��ȥ��
LONG                            
	); 
	set("outdoors", "shuidi");                                       
  	setup();
}              

void init()
{
        add_action("do_climb", "climb");
}

int do_climb()
{
        object me;
        me = this_player();

	tell_object(me,"���þ�ʣ�������ץס���ˣ���������\n");      
	me->move(__DIR__"yuanlin4");  
        return 1;
}

