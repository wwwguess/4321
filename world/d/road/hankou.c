
inherit ROOM;

void create()
{
	set("short", "ºº¿Ú");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rhktokf0.c",
	"south" : "/d/road/hkdukoub.c",
	"northwest" : "/d/road/rxytohk2.c",
]));

	setup();
	replace_program(ROOM);
}
