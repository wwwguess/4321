// Room: /d/new_taohua/chufang.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这屋由不剥皮的松木搭成。屋外攀满香藤，进屋后顿感一阵清凉。
屋内远比一般厨房洁净，无烟火之扰。二哑仆一拉风箱，一加柴
另一个正在煮饭。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "east" : __DIR__"shitang",
  
]));
	

	setup();

}
