#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���" NOR);
	set("long", @LONG
�����ͨ���������������������������·��
�˺ܶࡣ
LONG
	);
	set("exits", ([ 
  "west"  : __DIR__"road2",
  "east" : __DIR__"kunming",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

