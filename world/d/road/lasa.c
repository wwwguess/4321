
inherit ROOM;

void create()
{
	set("short", "À­Èø");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northeast" : "/d/road/rlstotgl0",
	"east" : "/d/road/rlstojs0",
]));

	setup();
	replace_program(ROOM);
}
