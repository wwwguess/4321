
inherit ROOM;

void create()
{
	set("short", "�䵱ɽ����");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"southeast" : "/d/road/rxytowds1",
	"west" : "/d/road/rwdstojm0",
        "westup" : "/d/wudang/shanmen",
]));

	setup();
	replace_program(ROOM);
}
