//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"小秦淮酒家二楼"NOR);
	set("long", @LONG
这是一家充满着异域情调的酒馆。这里不但供应本地的各种
名酒，你也可以买到来自西域或南洋的各种美酒。李白，贺
知章都是这里的常客。现在只有一个客人。
LONG         
	);   
	set("objects", ([
		"/d/jingcheng/npc/qinge.c" : 1,
]));

	set("exits", ([ 
  "down" : __DIR__"jiuguan.c", 
 
	]));
	setup();
	replace_program(ROOM);
}

