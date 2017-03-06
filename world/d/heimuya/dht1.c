// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","地火堂");
	set("long", @LONG
地板是由水磨石铺成。左右墙上挂著几幅字画，
正面的墙上高高地挂著一块大匾，上书“地火堂”
三字。匾下是一把太师椅.
LONG
	);

	set("exits", ([
		"out"  :__DIR__"yst",
		"north" :__DIR__"dht2",
	]));

	set("valid_startroom", 1);

	set("objects", ([ 
		__DIR__"npc/wangcheng" : 1,
        ]));
	setup();
}

