
inherit ROOM;

void create()
{
	set("short", "²ÝÔ­");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
//	"west" : "/d/road/rcytoxx0",
	"east" : "/d/road/rfttocy5",
]));

	setup();
	replace_program(ROOM);
}
