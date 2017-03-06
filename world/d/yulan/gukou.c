
inherit ROOM;

void create()
{
	set("short", "月亮谷谷口");
	set("long", @LONG
这是月亮谷谷口，前面是一座高大的峭壁，北方向可见一条雾气腾腾的深谷，
望着远处的山谷你有一种不祥的预感。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  	"west" : "/d/yulan/xiaolu",
 	"northdown" : "/d/moon/road",
]));
	setup();
	replace_program(ROOM);
}
