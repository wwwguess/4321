// Room: /d/jingcheng/nchkzh2.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ջ��¥");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"nchkzh",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
