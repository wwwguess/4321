
inherit ROOM;

void create()
{
	set("short", "¶É¿Ú");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/xiamen",
	"east" : "/d/road/taiwan",
]));

	setup();
	replace_program(ROOM);
}
