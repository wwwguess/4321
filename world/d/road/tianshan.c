
inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"southeast" : "/d/road/rtlftots4",
]));

	setup();
	replace_program(ROOM);
}
