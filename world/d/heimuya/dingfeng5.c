// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","青石大道");
	set("long", @LONG
	一条很气派的青石大道,路左边是饭堂,路右边是柴房
LONG
	);

	set("exits", ([
		"west"  :__DIR__"fangtang",
		"east"  :__DIR__"caifang",
		"north" :__DIR__"dingfeng6",
                "south" :__DIR__"dingfeng4",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

