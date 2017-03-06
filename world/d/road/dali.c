
inherit ROOM;

void create()
{
	set("short", "¥Û¿Ì");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/remstodl3",
]));

	setup();
	replace_program(ROOM);
}
