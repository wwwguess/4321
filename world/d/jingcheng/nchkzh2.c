// Room: /d/jingcheng/nchkzh2.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "客栈二楼");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"nchkzh",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
