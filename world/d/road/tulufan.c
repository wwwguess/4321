
inherit ROOM;

void create()
{
	set("short", "��³��");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northwest" : "/d/road/rtlftots0",
	"south" : "/d/road/rtlftosm0",
	"southwest" : "/d/road/rtlftohys0",
	"east" : "/d/road/rsmtotlf4",
]));

	setup();
	replace_program(ROOM);
}
