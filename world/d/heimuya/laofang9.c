// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25
#include <room.h>
inherit ROOM;

void create()
{
	set("short","牢房");
	set("long", @LONG
这里黑沉沉的，即无一丝光亮，也无半分声息。黑暗中依稀
可以看到身边似乎有几个人影，看到你转过头去，他们立刻屏住
呼吸，紧张地瞪着你。
LONG
	);

	set("exits", ([
		"north" :__DIR__"laofang7.c",
  	]));
	set("objects", ([
          __DIR__"npc/fanren2" : 1 ]) );

	create_door("north", "铁门", "south", DOOR_CLOSED);
	setup();
}

