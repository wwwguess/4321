// /d/xingxiu/silk4.c
// Jay 3/17/96
#include <room.h>

inherit ROOM;

void create()
{ 
       set("short","大沙漠");
       set("long", @LONG
这是一片一望无际的大沙漠。你一进来就迷失了方向。
看来要走出这块沙漠并非易事。
LONG
     );
//        set("outdoors", "xingxiuhai");
    
	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"shamo2",
		"south" : __DIR__"shamo3",
		"north" : __DIR__"shamo4",
	]));             
        setup();

//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( dir == "west")
            me->add_temp("mark/steps",1);
	if ( dir == "east")
            me->add_temp("mark/steps",-1);

	if (me->query_temp("mark/steps") == 10)
         {
     	    me->move("/d/xingxiu/btshan");
            me->delete_temp("mark/steps");
             return notify_fail("你累得半死，终於走出了沙漠。\n");
         }  

     if (me->query_temp("mark/steps") == -10)
	    {  
	       me->move("/d/xingxiu/silk4");
           me->delete_temp("mark/steps");
             return notify_fail("你累得半死，终於走出了沙漠。\n");
     	}

        return ::valid_leave(me,dir);
}
