
inherit ROOM;

void create()
{
	set("short", "���϶ɿ�");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rhntodk0",
	"south" : "/d/road/nansha",
]));

	setup();
	replace_program(ROOM);
}
