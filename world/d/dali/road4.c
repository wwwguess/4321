#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "��ʯ�ٵ�" NOR);
	set("long", @LONG
����һ����ʯ�ٵ���������Ǵ�����ˡ����Ϸ�
�Ķ���ˮ���������м����洬�������㡣
LONG
	);
	set("exits", ([ 
  "west"  : __DIR__"dalicheng",
  "southeast" : __DIR__"road3",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

