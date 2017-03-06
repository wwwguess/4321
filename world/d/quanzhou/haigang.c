// Room: /d/quanzhou/haigang.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "海港");
	set("long", @LONG
 这里是出海的必经之路,港口停着许多船。
LONG
	);

	set("exits", ([
             "enter" : "/d/taohua/boat",
                "west" : __DIR__"dongjie",
	]));

	set("objects", ([
                //__DIRIR__"npc/boater":1,
                __DIR__"npc/boy":2,
                __DIR__"npc/girl":1,
	]));

	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

