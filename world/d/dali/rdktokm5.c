#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���" NOR);
	set("long", @LONG
��Χ���˶������ˣ�ȥ�����ǵ��˶������������ء�
LONG
	);
	set("exits", ([ 
  "northwest"  : __DIR__"rdktokm4",
  "southeast" : __DIR__"kunming",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

