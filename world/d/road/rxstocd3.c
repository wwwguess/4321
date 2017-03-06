#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "驿道" NOR);
	set("long", @LONG
这是一条宽广的大道! @来往的行人很多.旁边有很多的客栈和茶馆.时常有一匹匹快马
奔驰而过,扬起一阵尘烟,原来是官府的捕快在执行工务!
LONG
	);
	set("exits", ([ 
  "west"  : __DIR__"rxstocd2",
  "east" : __DIR__"rxstocd4",
  "south": "/u/m/mic/mic2.c"
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
}

void init()
{	
        return;
}

