#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "ɽ·" NOR);
	set("long", @LONG
һ��ɽ·��������Զ���������죬������Զû�о�ͷ��
LONG
	);
	set("exits", ([ 
  "northeast"  : __DIR__"qinghaihu",
  "south" : __DIR__"rqhhtokl4",
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

