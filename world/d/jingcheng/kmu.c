// Room: /d/jingcheng/kmu.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m¿×¼ÇÄ¾Æ÷µê[2;37;0m");
	set("long", @LONG
ÕâÊÇÒ»¼Ò×¨ÊÛÄ¾Æ÷µÄÐ¡µê£¬µêÃæ²»´ó£¬È´ºÜÕû½à¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"zhq6",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kong" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
