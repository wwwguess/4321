#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"朱雀大街"NOR);
	set("long", @LONG
这里是朱雀大街的中段。北面是一家布店，东面是朱雀大街和南门
大街的十字路口。那里正是京城的必游之地，饭庄旅馆银行当铺等
老字号汇集之处，往来人群不断。
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq2",
 "east" :__DIR__"ndj3",  
 "north" :__DIR__"bdian",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

