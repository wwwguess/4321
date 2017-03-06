// Room: /d/jingcheng/yfangup.c
// Made by: ysgl  
//added by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"乐坊二楼"NOR);
	set("long", @LONG
乐坊楼上显得格外热闹，走廊里人来人往，几间屋子里人声
嘈杂，牌签骨骰钱币落盘的声音不绝。看样子，客人们赌得
正欢呢。
LONG
	); 
	set("objects", ([
		__DIR__"npc/eba.c" : 1,
		__DIR__"npc/liuyuer.c" : 1,
		__DIR__"npc/genu.c" : 2,
]));
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"cayfang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
