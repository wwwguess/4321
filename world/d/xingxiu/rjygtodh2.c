#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "˿��֮·" NOR);
	set("long", @LONG
�������ľ������������,�쵽˿��֮·�ϵ�С�������.
LONG
	);
	set("exits", ([ 
  "east"  : __DIR__"rjygtodh1",
  "northwest" : __DIR__"dunhuang",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
	object me = this_player();
	
        return;
}

