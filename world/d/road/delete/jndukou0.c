
inherit ROOM;

void create()
{
	set("short", "���϶ɿ�");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/jndukou1",
	"south" : "/d/road/rdktojn0",
]));

	setup();
	replace_program(ROOM);
}
