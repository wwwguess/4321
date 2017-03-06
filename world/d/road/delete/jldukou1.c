
inherit ROOM;

void create()
{
	set("short", "½ðÁê¶É¿Ú");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/jldukou0",
	"south" : "/d/road/jinling",
]));

	setup();
	replace_program(ROOM);
}
