// Room: /d/road/rcdtojs1.c

inherit ROOM;

void create()
{
	set("short", "鬼宅");
	set("long", @LONG
这是鬼魂老出没的地方
LONG
);
	set("outdoors", "road");
	set("exits", ([ /* sizeof() == 3 */
		"west" : __DIR__"rcdtojs2",
		"south" : __DIR__"rcdtojs1.c",
		"east" : __DIR__"rcdtojs0",
]));
	setup();
	replace_program(ROOM);

}
