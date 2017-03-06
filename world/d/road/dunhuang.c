
inherit ROOM;

void create()
{
	set("short", "¶Ø»Í");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northwest" : "/d/road/rdhtoym0",
	"west" : "/d/road/dhshamo",
	"southeast" : "/d/road/rjygtodh2",
]));

	setup();
	replace_program(ROOM);
}
