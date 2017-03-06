//ROOM: /d/shanzhuang/qyuan.c
//by dwolf
//97.11.5

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", "富贵山庄的前院布满了各种奇花异草，最多的是腊梅，奇怪的是
这儿的腊梅一年到头总开着。院中有两个少年正在聊天。他们穿得很破，但看上去却很
快乐。他们好象在争论什么。\n");  
	set("exits", ([
		"south" : "/u/dwolf/test/door.c",
		"north" : "/u/dwolf/test/ting.c",
		"west" : "/u/dwolf/test/kefan1.c",
		"east" : "/u/dwolf/test/kefan2.c",  
	])); 
	set("objects", ([
		"/u/dwolf/test/npc/zuo.c" : 1,
		"/u/dwolf/test/npc/wang.c" : 1,
]));	
	setup();
	replace_program(ROOM);
}
