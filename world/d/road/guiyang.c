
inherit ROOM;

void create()
{
	set("short", "πÛ—Ù");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rgytodk0",
	"northeast" : "/d/road/rgytocs0",
//	"southwest" : "/d/road/rgytodl0",
	"southwest" : "/d/dali/eroad4",
]));

	setup();
	replace_program(ROOM);
}
