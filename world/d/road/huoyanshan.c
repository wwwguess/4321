
inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"southwest" : "/d/road/rhystoks0",
	"northeast" : "/d/road/rtlftohys4",
]));

	setup();
	replace_program(ROOM);
}
