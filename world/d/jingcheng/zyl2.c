//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"紫阳楼二楼"NOR);
	set("long", @LONG
紫阳楼是长安城里最有名的一个饭馆了。这里不但常常有京城里的
达官贵人的排场宴请，还每天接待着从各地慕名而来的游人。这儿
客人不少，正吃得开心呢。
LONG         
	);

	set("exits", ([ 
  "down" :__DIR__"zyl.c", 
 
	]));   
	set("objects", ([
	__DIR__"npc/guest1.c" : 4,
]));
	setup();
	
}

