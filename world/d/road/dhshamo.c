
inherit ROOM;

void create()
{
	set("short", "��ɳĮ");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/dhshamo",
	"east" : "/d/xingxiu/dunhuang",
]));

	setup();
	replace_program(ROOM);
}
