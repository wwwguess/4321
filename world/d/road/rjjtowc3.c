#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���" NOR);
	set("long", @LONG
�������������ˣ�·�ϵ��˶���������
LONG
	);
	set("exits", ([ 
  "northwest"  : __DIR__"wuchang",
  "northeast" : __DIR__"rjjtowc2",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

