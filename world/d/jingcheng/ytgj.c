#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"袁天罡家"NOR);
	set("long", @LONG
这里便是当朝钦天监台正先生袁天罡的家。屋里看起来并不是很阔
气．袁天罡整日在朝中做事，经常是几日才回家一次，家中冷冷清
清的。
LONG         
	);

	set("exits", ([ 
 "east"  :__DIR__"ql5",
 	]));
	setup();
	
}

