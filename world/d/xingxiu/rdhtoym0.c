#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "˿��֮·" NOR);
	set("long", @LONG
�����·��������,��ɳ�ܴ�,��ʱ����ɳʯ.
LONG
	);
	set("exits", ([ 
  "north"  : __DIR__"yumenguan",
  "southeast" : __DIR__"dunhuang",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
	object me = this_player();
	
        return;
}

