// Room: /d/new_taohua/nanpuroom.c
//write by lysh
inherit ROOM;

void create()
{
	set("short", "女仆卧室");
	set("long", @LONG
这屋由不剥皮的松木搭成。屋外攀满香藤，进屋后顿感
一阵清凉。屋内空空荡荡，数十张床整齐排列，二名女
哑仆正在打扫房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "west" : __DIR__"qianting",
]));

	setup();
	replace_program(ROOM);
}
