
inherit ROOM;

void create()
{
	set("short", "��ɳȺ��");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/hndukou",
]));

	setup();
	replace_program(ROOM);
}
