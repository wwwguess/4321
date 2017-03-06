
inherit ROOM;

void create()
{
	set("short", "±ùÉ½");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rsmtobs4",
	"south" : "/d/road/rbstols0",
]));

	setup();
	replace_program(ROOM);
}
