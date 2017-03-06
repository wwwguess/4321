
inherit ROOM;

void create()
{
	set("short", "‘¿—Ù");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northeast" : "/d/road/rwctoyy3.c",
	"south" : "/d/road/ryytocs0.c",
]));

	setup();
	replace_program(ROOM);
}
