//ROOM: /d/suzhou/szroad6.c
//by dwolf
//97.11.5

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"大驿道"NOR);
	set("long", @LONG
你走在一条静谧的小道上，远处能否看到森林，依稀能听到猛兽的吼声。道路两旁
是整整齐齐的杨树林。东边就是苏州城了。路上可以看到一些去打猎的人。
LONG 
	);
	set("exits", ([
		"east" : __DIR__"wgate",
		"west" : __DIR__"szroad7",
]));
	setup();
	replace_program(ROOM);
}
