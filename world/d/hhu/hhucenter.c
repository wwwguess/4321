// Room: /d/snow/sroad3.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "网络中心实验室");
	set("long", @LONG
这里是网络中心实验室：
屋子里是三排计算机，屋角有个大空调，另一边是书架，有
一个投影屏幕放在正前方。旁边还摆着一个电话，这是与
校内其他用户互通消息的榘道，您也可以来这儿询问有关
上网问题.
LONG
	);
	set("exits",([ /* sizeof() ==2 */
	"north": __DIR__"roadtocenter1",
	"up": __DIR__"center_2f",
]));
	set("objects", ([
		__DIR__"npc/yanjiusheng": 1 ]) );

        create_door("north","防盗门","south",DOOR_CLOSED);
	setup();
}
