// Room: /d/jingcheng/jjun2.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jiangjun",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qin-bg" : 1,
        __DIR__"npc/xtong" : 3,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
