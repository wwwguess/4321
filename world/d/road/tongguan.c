
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/rtgtoca0",
	"east" : "/d/road/rlytotg3",
]));

	setup();
	replace_program(ROOM);
}
