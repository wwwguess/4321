#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"小秦淮酒家"NOR);
	set("long", @LONG
这是一家充满着异域情调的酒馆。这里不但供应本地的各种
名酒，你也可以买到来自西域或南洋的各种美酒。李白，贺
知章都是这里的常客。
LONG         
	);   
	set("objects", ([
		"/d/jingcheng/npc/waiter.c" : 1,
]));
        // This enables players to save this room as their startroom.
        set("valid_startroom", 1);

	set("exits", ([ 
 "west" :__DIR__"baih5",
 "up" : __DIR__"jiuguan2.c", 
 
	]));
	setup();
	replace_program(ROOM);
}

