
inherit ROOM;

void create()
{
	set("short", "МЁНе");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/dukou",
]));

	setup();
	replace_program(ROOM);
}
