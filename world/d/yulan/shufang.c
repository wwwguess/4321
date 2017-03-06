
inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这里是一间整理得相当乾净的书房，红木桌椅上铺著蓝绸巾，显得十分
考究，西面的立著一个书架，上面放著一排排的古书，往南走出房门可
以看到大厅。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"north" : "/d/yulan/yulanhall",
]));

	setup();
	replace_program(ROOM);
}
