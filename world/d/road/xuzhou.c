
inherit ROOM;

void create()
{
	set("short", "徐州");
	set("long", @LONG
这儿就是徐州古城，历来是兵家必争之地。
从这儿往南就到金陵（南京）、西边是去开封的驿道。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rjntoxz2",
	"west" : "/d/road/rxztokf0",
	"south" : "/d/road/rxztodk0",
]));

	setup();
	replace_program(ROOM);
}
