
inherit ROOM;

void create()
{
	set("short", "青海湖");
	set("long", @LONG 
这里就是中国最大的内陆湖泊：青海湖。这里的湖水很咸，
是无法喝的。远远向湖面望去，波涛点点，但无什么动静。
西南方向就是通往江湖人士谈虎色变的星宿海� 西边则要到昆仑山了。
虽然很远，但也能依稀看到巍巍昆仑山的皑皑白雪。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"southeast" : "/d/xingxiu/rqhhtolz0",
	"southwest" : "/d/road/rqhhtoxsh0",
	"west" : "/d/road/rqhhtokl0",
]));

	setup();
	replace_program(ROOM);
}
