#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"水果店"NOR);
	set("long", @LONG
这里是一间水果店，柜台上摆满了各种时令鲜果，阵阵诱人的香气
让人口水直流。老板拿着一把拂尘，一边敢苍蝇，一边笑眯眯地招呼
顾客。
LONG         
	);   
	set("objects", ([
		__DIR__"t.c" : 1,
]));

	set("exits", ([ 
 "east" :"/d/jingcheng/baih6",
 	]));
	setup();
	
}

