
inherit ROOM;

void create()
{
	set("short", "Ñ¼ÂÌ½­¶É¿Ú");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/rfttogl2",
]));

	setup();
	replace_program(ROOM);
}
