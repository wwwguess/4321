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
  "north"  : __DIR__"rlstotgl2",
  "southwest" : __DIR__"rlstotgl0",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
return;
}

