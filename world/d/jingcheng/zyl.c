//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"紫阳楼"NOR);
	set("long", @LONG
紫阳楼是长安城里最有名的一个饭馆了。这里不但常常有京城里的
达官贵人的排场宴请，还每天接待着从各地慕名而来的游人。你刚
一踏进门，店小二就殷勤地迎了上来。
LONG         
	);

	set("exits", ([ 
 "south" :__DIR__"xchjie2",
 "up" :__DIR__"zyl2.c", 
 
	]));   
	set("objects", ([
	__DIR__"npc/waiter2.c" : 1,
]));
	setup();
	
}

