#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"古董店"NOR);
	set("long", @LONG
这家的老板姓林，自他祖辈起就搞这古董生意。屋里的摆设也是古
香古气，墙上的画，地上的椅，桌上的瓶．．．一件件看起来都那
么珍爱。
LONG         
	);  
	set("objects", ([
		"/d/jingcheng/npc/lin.c" : 1,
]));

	set("exits", ([ 
 "west" :__DIR__"chhgch",
 	]));
	setup();
	
}

