#include <room.h>

inherit ROOM;

void create()
{
	set("short", "长沙城大门");
	set("long", @LONG
通过守门士兵的一番盘查，你被放入城内。腾龙城内熙熙攘攘，人来人往。
一派繁荣的景象。人们脸上都带着宽厚的笑容。由这条宽阔的大街向
西望去，依稀可以看见都督府的大门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/yulan/gate3",
  "east" : "/d/yulan/gate1",
]));

       create_door("east", "长沙城大门", "west", DOOR_CLOSED);

        set("no_clean_up", 0);
       	set("outdoors", "maintown");

	setup();
	replace_program(ROOM);
}
