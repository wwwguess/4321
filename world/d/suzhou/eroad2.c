//ROOM: d/suzhou/eroad2.c
// by dwolf
// 97.11.4

#include <ansi.h>   
inherit ROOM;

void create()
{
	set("short", MAG"东大街"NOR);
	set("long", @LONG
	   这是一条宽阔的青石板街道，向东西两头延伸。东大街是衙门所在，行人
稀少，静悄悄地很是冷清。西边远处传来喧闹声。南边是兵营。北边就是衙门了。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"eroad1",  
		"north" : __DIR__"yamen",
		"south" : __DIR__"bingyin",
		"east" : __DIR__"egate",
]));                                     
	setup();
}





