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
LONG
	);
	set("exits", ([ 
  "northeast"  : __DIR__"rcytoxx4",
  "southwest" : __DIR__"xixia",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

