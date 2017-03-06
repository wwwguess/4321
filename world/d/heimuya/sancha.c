// Room: /d/heimuya/.c
// write by: dfbb 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","路口");
	set("long", @LONG
这是一个路口,往北二十里就是平安州保定城,往西北四十里就是有名的
猩猩滩。路上行人匆匆忙忙的都赶着进城。西南方向通往一个岔道，可
以由此到达猗云镇。路西是一家客栈。

LONG
	);

	set("exits", ([
		"north" :__DIR__"bdcm",
                "northwest" :__DIR__"xxt1",
                "west" :__DIR__"kezhan",
                "southwest" :__DIR__"yidao1",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

