
inherit ROOM;

void create()
{
	set("short", "开封");
	set("long", @LONG
这里就是中原名城开封。这里的包青天的包公祠可是值得
一去。铁塔，潘、杨二湖也很有一番景致的。
这里往东是去兵家重镇徐州。往南就到武昌了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rkftodk0",
	"south" : "/d/road/rhktokf4",
	"west" : "/d/road/rjdtoly0",
	"east" : "/d/road/rxztokf3",
]));

	setup();
	replace_program(ROOM);
}
