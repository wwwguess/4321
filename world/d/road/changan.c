
inherit ROOM;

void create()
{
	set("short", "³¤°²");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/rcatolz0",
	"east" : "/d/road/rtgtoca2",
]));

	setup();
	replace_program(ROOM);
}
