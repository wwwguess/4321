#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"吉祥杂货铺"NOR);
	set("long", @LONG
不知为什么西城虽大，却只有这一间杂货铺。所以每天人来人往，
也挺热闹。这里无论是油盐酱醋，还是大米白面，样样齐全。屋
里打扫的也十分干净，魏老板在和几位客人说说笑笑。
LONG         
	); 
	set("objects", ([
		"/d/jingcheng/npc/wei.c" : 1,
]));

	set("exits", ([ 
 "west"  :__DIR__"ql5",
 	]));
	setup();
	
}

