// Room: /d/heimuya/.c
// write by: dfbb 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","驿道");
	set("long", @LONG
    这是通向 "保定城"的驿道。四周人来人往。挑担子的
行商，赶着大车的马夫，上京赶考的书生，熙熙攘攘，非常热闹。
不过路边开始有一些穿黑衣服的人经过.

LONG
	);

	set("exits", ([
		"south" :__DIR__"yidao1",
		"north" :__DIR__"yidao3",

	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

