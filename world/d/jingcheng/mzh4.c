#include <ansi.h>
inherit ROOM;    

void create()
{
      set("short", HIW"民宅"NOR);
	set("long", @LONG
一间小小的民宅，打扫的干干净净。家俱不是很好，最显眼的就是一
张长桌，上有文房四宝笔墨纸砚，还有一面小牌子(paizi)，桌旁放了
几把木椅，一个小炉上放着一个铁壶，冒着淡淡水气。
LONG         
	);
        set("item_desc", ([
		"paizi" : "男儿当自强.\n",
]));    
	set("objects", ([
		__DIR__"npc/liver3.c" : 1,
]));
 
	set("exits", ([ 
 		"west"  :__DIR__"ql3",
 	]));
	setup();
	
}

