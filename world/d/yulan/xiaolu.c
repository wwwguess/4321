
inherit ROOM;

void create()
{
	set("short", "山间小路");
	set("long", @LONG
这是一条普通的山间小路，弯弯曲曲往东而去，往东可见月亮谷谷口。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/yulan/secrect2",
  "east" : "/d/yulan/gukou",
]));
	setup();
	replace_program(ROOM);
}
