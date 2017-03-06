// Room: /d/road/jingdu.c

inherit ROOM;

void create()
{
	set("short", "京都南驿站");
	set("long", @LONG
你来到了京城外。不远处可以看到高耸的城墙和紫禁城的屋檐。城门口
很多御林军在盘查行人。近来朝廷对江湖人物限制很严，还是不要到天子
脚下捣乱的好。
    再往北走就到了京师的南门。东北方向到山海关,西南方向到保定、
开封等南方。�.
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
		"southwest" : __DIR__"rdktojd4",
		"southeast" : __DIR__"rjdtodk0",
		"north" : "/d/city/sroad1",
//		"west" : __DIR__"rjdtoly0",
		"northeast" : __DIR__"rjdtoshg0",
]));

	setup();
	replace_program(ROOM);
}
