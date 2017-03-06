
inherit ROOM;

void create()
{
	set("short", "¿¦Ê²");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northeast" : "/d/road/rhystoks4",
	"southeast" : "/d/road/rkstosm0",
]));

	setup();
	replace_program(ROOM);
}
