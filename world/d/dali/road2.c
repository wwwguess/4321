#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "ɽ·" NOR);
	set("long", @LONG
һ�����ѵ�ɽ·��������Զ�����죬������Զû�о�ͷ��
LONG
	);
	set("exits", ([ 
  "west"  : __DIR__"road3",
  "east" : __DIR__"road1",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

