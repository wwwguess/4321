
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/rjltosz1",
	"south" : "/d/road/rhztosz0",
]));

	setup();
	replace_program(ROOM);
}
