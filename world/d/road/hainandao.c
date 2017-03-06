
inherit ROOM;

void create()
{
	set("short", "º£ÄÏµº");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/gzdukou",
	"south" : "/d/road/rhntodk0",
]));

	setup();
	replace_program(ROOM);
}
