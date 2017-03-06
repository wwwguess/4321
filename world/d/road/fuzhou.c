
inherit ROOM;

void create()
{
	set("short", "ИЃжн");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/rfztoyt0",
//	"east" : "/d/road/dukou",
]));

	setup();
	replace_program(ROOM);
}
