
inherit ROOM;

void create()
{
	set("short", "���Ź�");
	set("long", @LONG
������ǽ��Źأ���������һ��С��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rwdstojm4",
	"southwest" : "/d/road/rjmtocd0",
        "northeast" : "/d/chuenyu/dustyroad0",
]));

	setup();
	replace_program(ROOM);
}
