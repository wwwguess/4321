//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"春水客栈"NOR);
	set("long", @LONG
春水客栈是长白山附近最有名的一家客栈，哪些进关东来采购皮毛，人参
的商人一般都要到这儿歇歇脚，喝上两盅老白干。这儿的小二也很热情，
一踏进门，店小二就殷勤地迎了上来。
LONG         
	);

	set("exits", ([ 
 "southwest" :"/d/road/rfttocbs1",
 
	]));   
	set("objects", ([
	__DIR__"npc/waiter2.c" : 1,
]));
	setup();
	
}

