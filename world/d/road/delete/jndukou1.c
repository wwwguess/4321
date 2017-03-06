
inherit ROOM;

void create()
{
	set("short", "¼ÃÄÏ¶É¿Ú");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rjdtodk3",
	"south" : "/d/road/jndukou0",
]));

	setup();
	replace_program(ROOM);
}
