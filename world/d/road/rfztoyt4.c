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
�������߾͵����ݳ��ˡ�
LONG
	);
	set("exits", ([ 
  "north"  : "/d/road/hangzhou",
  "southeast" : __DIR__"rfztoyt3",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

