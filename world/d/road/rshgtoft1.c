#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���" NOR);
	set("long", @LONG
ʱ����һƥ�����޶�����ԭ���ǹٸ��Ĳ�������ִ�й���
LONG
	);
	set("exits", ([ 
  "northeast"  : __DIR__"rshgtoft2",
  "south" : __DIR__"rshgtoft0",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

int is_road() {
	return(1);
}

