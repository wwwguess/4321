#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"总管府第"NOR);
	set("long", @LONG
这里是当朝总管殷开山的府第。大门两侧有两头高大的石狮子。
院子里种满了花草。东边是一棵槐树，郁郁葱葱，遮盖了大半
个院子。一条长廊走道通往后院。
LONG         
	);

	set("exits", ([ 
 "north" :__DIR__"xchjie4", 
 
	]));
     set("objects",([
      __DIR__"npc/yingks.c" :1,
      __DIR__"npc/xunbu.c" : 3,
    ]));
	setup();
	
}

