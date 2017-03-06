// Room: /d/heimuya/.c
// write by: dfbb 
// date 97/01/25

#include <localtime.h>
inherit ROOM;
int flag=0;

void create()
{
	set("short","驿道");
	set("long", @LONG
    这是通向 "保定城"的驿道。四周人来人往。
北边就快到保定城了,西边是一家老字号的客栈
"顺升客栈".	
LONG
	);

	set("exits", ([
		"south" :__DIR__"yidao4",
		"north" :__DIR__"sancha",
                "west"  :__DIR__"kezhan",
	]));

	set("outdoors", "heimuya");
	setup();
}

