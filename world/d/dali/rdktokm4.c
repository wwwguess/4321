#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���" NOR);
	set("long", @LONG
������һ�����̺��ٵ��������Χɽ�����࣬˵����
��ǿ����û�����ǿ��߰ɡ�
LONG
	);
	set("exits", ([ 
  "north"  : __DIR__"rdktokm3",
  "southeast" : __DIR__"rdktokm5",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

