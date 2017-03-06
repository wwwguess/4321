
inherit ROOM;

void create()
{
	set("short", "Ã∆π≈¿≠…Ω");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northdown" : "/d/road/rkltotgl2",
	"southdown" : "/d/road/rlstotgl2",
]));

	setup();
	replace_program(ROOM);
}
