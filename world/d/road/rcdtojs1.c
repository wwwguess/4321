// Room: /d/road/rcdtojs1.c

inherit ROOM;

void create()
{
	set("short", "��լ");
	set("long", @LONG
���ǹ���ϳ�û�ĵط�
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
