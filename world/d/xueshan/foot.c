// foot.c
//by dwolf  
  
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ѩɽɽ��");
	set("long", @LONG
	  ����ɭ�������ư˹գ���Ȼ������ѩɽ���¡�ֻ��ѩɽ�������ƣ��嶥��
����һ��ׯ԰����ԼԼ������ѩ���С�
LONG
	);

	set("exits", ([
		"north" : __DIR__"forest5.c",
	 ]));
}            

void init()
{
	add_action("do_climb", "climb");    
//	add_action("do_push", "push");
}      

int do_climb(string arg)
{
        object me;
        object obj;
        object ob;
        ob = this_player();
        
        if ( !arg || arg != "up")
                return notify_fail("��Ҫ��ʲ��?\n");
        
        me=this_player();
        
        if ( ((int)me->query_skill("dodge") < 100) ) { 
                tell_object(me, "���Ṧ̫�ͣ�������ȥ��\n");
                return 1;
        }

        else if( ((int)me->query("kee")<500))
             {tell_object(me, "��������̫��ร�\n");  

		return 1;
             }
 
        me->receive_damage("gin",50);
        me->receive_damage("kee",50);
        message_vision("$N�ֽŲ��ã���������������\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("$N����������ȥ��\n",me);
                this_player()->move(__DIR__"road1");
                message("vision","$N��ǰ��һ��ѩɽС��.\n",
        environment(me),me);
                tell_room(__DIR__"road1","$N������ѩɽ��\n",me);
                return(1);
        }
        return(1);
}
/*                                      
int do_push(string arg)
{
	object me;
	me=this_player();
        if(!arg )
                return notify_fail("push <��>\n");
        if(query("exits/down")) return 0;
        if( arg=="grass") 
                        message_vision( "\n$N�Ѳݴ��ƿ���¶��һ�����µ�С·��\n",me);
	                set("exits/down",__DIR__"ywgu");
                        return 1;
}                   
*/
void reset()
{
    ::reset();
    if(query("exits/down"))
    	delete("exits/down");
}


                                                
