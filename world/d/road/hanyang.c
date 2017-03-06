
inherit ROOM;

void create()
{
	set("short", "บบั๔");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/hkdukoun.c",
]));

	setup();
	replace_program(ROOM);
}
