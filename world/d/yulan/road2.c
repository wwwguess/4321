inherit ROOM;

void create()
{
	set("short", "小石桥");
	set("long", @LONG
这是一条普通的小石桥，桥下是一条小溪，水面上飘着一层玉兰花的花
瓣，往西是一条青石小路，往东在一片树林中现出一个村庄。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : "/d/yulan/yulan_gate",
  "west" : "/d/yulan/road1",
]));

	setup();
	replace_program(ROOM);
}
