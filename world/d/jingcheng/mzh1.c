#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"民宅"NOR);
	set("long", @LONG
这户民宅从结构上看还是相当不错的，显示出这户人家先前似乎曾
经阔过。不知从哪一辈起家道开始衰落了，这座房子也随之年久失
修。现在这户人家的三个儿子更是整日里游手好闲，不务正业。
LONG         
	);

	set("objects", ([ 
        __DIR__"npc/baijia" : 3,
      ]));

	set("exits", ([ 
	 "west" :__DIR__"ql1",
 	]));

	setup();
	
}

