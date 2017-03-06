
inherit ROOM;

void create()
{
	set("short", "Îä²ý");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"southeast": __DIR__"rjjtowc3",
	"north" : __DIR__"hkdukoun.c",
	"south" : __DIR__"rwctoyy0.c",
]));
	set("outdoors","road");
	setup();
	replace_program(ROOM);
}
