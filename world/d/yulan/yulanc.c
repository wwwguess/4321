
inherit ROOM;

void create()
{
	set("short", "玉兰山庄后院");
	set("long", @LONG
这是玉兰山庄的后院，院中种着几株白玉兰树，向西是玉兰山庄的
大厅，向北是茂密的玉兰树林。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"east" : "/d/yulan/xiaoyuan",
	"west" : "/d/yulan/yulanhall",
	"north" : "/d/yulan/yulanlin",
	"south" : "/d/yulan/houting",
]));

	setup();
	replace_program(ROOM);
}
