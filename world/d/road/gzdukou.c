
inherit ROOM;

void create()
{
	set("short", "���ݶɿ�");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rgztodk0",
	"south" : "/d/road/hainandao",
]));

	setup();
	replace_program(ROOM);
}
