#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���" NOR);
	set("long", @LONG
һ�������������Զ�����죬������Զû�о�ͷ��
LONG
	);
	set("exits", ([ 
  "west"  : "/d/road/rjjtowc1",
  "east" : "/d/road/jiujiang",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

