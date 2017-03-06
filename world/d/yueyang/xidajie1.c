// Room: /city/xidajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
	这是一条宽阔的青石板街道，向东西两头延伸。西大街是衙门所在，行人
稀少，静悄悄地很是冷清。东边是一个热闹的广场。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"guangchang",
		"west" : __DIR__"ximen",
	]));
        set("objects", ([
                __DIR__"npc/wolfdog" : 1,
        ]));


	setup();
	replace_program(ROOM);
}

