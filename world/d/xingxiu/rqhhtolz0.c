#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���" NOR);
	set("long", @LONG
����һ���������,�������,��ʱ���������ɳ,·�߼��ð���,
ȴ��ֱͦ��.�����߾͵����ݵĻƺӶɿ���.
LONG
	);
	set("exits", ([ 
  "northwest"  : "/d/road/qinghaihu",
  "east" : __DIR__"rqhhtolz1",
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

