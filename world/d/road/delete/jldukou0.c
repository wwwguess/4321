
inherit ROOM;

void create()
{
	set("short", "����ɿ�");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rxztodk3",
	"south" : "/d/road/jldukou1",
]));

	setup();
	replace_program(ROOM);
}
