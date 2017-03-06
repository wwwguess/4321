
inherit ROOM;

void create()
{
	set("short", "¶λαÒΙ½");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rcdtoems3",
	"south" : "/d/road/remstodl0",
]));

	setup();
	replace_program(ROOM);
}
