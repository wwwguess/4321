
inherit ROOM;

void create()
{
	set("short", "ÄÏÉ³Èºµº");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/hndukou",
]));

	setup();
	replace_program(ROOM);
}
