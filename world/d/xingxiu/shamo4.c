// Room: /d/xingxiu/shamo4.c

#include <room.h>
inherit ROOM;

void create()
{
       set("short","��ɳĮ");
       set("long", @LONG
����һƬһ���޼ʵĴ�ɳĮ����һ��������ʧ�˷���
����Ҫ�߳����ɳĮ�������¡�
LONG
     );
	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"shamo1",
		"south" : __DIR__"shamo2",
		"north" : __DIR__"shamo3",
	]));
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
       if (dir == "west")
          me->add_temp("mark/steps",1);
       if (dir == "east")
          me->add_temp("mark/steps",-1); 
        
	if (me->query_temp("mark/steps") == 10)
         {
     	    me->move("/d/xingxiu/btshan");
            me->delete_temp("mark/steps");
             return notify_fail("���۵ð���������߳���ɳĮ��\n");
         }  

     if (me->query_temp("mark/steps") == -10)
	    {  
	       me->move("/d/xingxiu/silk4");
           me->delete_temp("mark/steps");
             return notify_fail("���۵ð���������߳���ɳĮ��\n");
     	}
           
        return ::valid_leave(me, dir);
}
