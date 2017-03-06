// Room: /d/snow/inn_3f.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "饮风客栈三楼");
	set("long", @LONG
你现在来到了饮风客栈的三楼，这里是武林盟主居住的地方，每天都有许多人
来这里一睹武林至尊的的风采，墙上有一幅画，是老猫的笔墨。

           多少武林旧事，空回首，如烟纷飞。
               斜阳外，寒鸦数点，流水绕孤村。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	//	"west" : __DIR__"w_room",
	//	"north" : __DIR__"n_room",
		"down" :"/d/snow/inn_2f",
	//	"east" : __DIR__"e_room",
	]));
	
	set("objects", ([
		"/obj/sbaa/mengzhu":	1,
		]));

	//create_door("north", "房门", "south", DOOR_CLOSED);
//	create_door("east", "房门", "west", DOOR_CLOSED);
	//create_door("west", "房门", "east", DOOR_CLOSED);

	setup();
}
