#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"破旧民宅"NOR);
	set("long", @LONG
这栋房子里象是很久没有人居住了，墙脚屋檐下到处都是灰。还经
常可以看到肥肥的老鼠跑来跑去。院中杂草从生，还可听到几声蛐
蛐叫。
LONG         
	);  
	set("objects", ([
		__DIR__"npc/rat.c" : 4,
]));
	set("exits", ([ 
 "north" :__DIR__"zhq4",
	]));
	setup();
	replace_program(ROOM);
}

