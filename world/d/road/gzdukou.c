
inherit ROOM;

void create()
{
	set("short", "¹ãÖÝ¶É¿Ú");
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
