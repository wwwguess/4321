#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIY "�������" NOR);
	set("long", @LONG
����һ���û������͵Ĵ����������һ�Σ���ʹ�˻�ͷ���ԣ�
һ�������
LONG
	);
	set("exits", ([ 
  "southeast"  : __DIR__"rdktojyg1",
  "northwest" : __DIR__"rdktojyg3",
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

