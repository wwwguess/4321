// Room: /d/taohua/yaopinfang.c

inherit ROOM;

void create()
{
	set("short", "药品房");
	set("long", @LONG
这里药气冲天，桌上榻上地上，到处放满了诸般药物以及大大小小的瓶
儿，罐儿，缸儿，钵儿。一哑仆正在用小火煎着药。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "south" : __DIR__"zhuangbeiku",
  "north": __DIR__"wuqiku",
 
]));
set("objects", ([
		CLASS_D("taohua") + "/yapu.c" : 1,
          __DIR__"npc/di-zi2" : 3,
	]));
	       

	setup();

}
