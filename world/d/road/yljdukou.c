
inherit ROOM;

void create()
{
	set("short", "Ѽ�̽��ɿ�");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/rfttogl2",
]));

	setup();
	replace_program(ROOM);
}
