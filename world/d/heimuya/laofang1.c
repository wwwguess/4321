// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25
#include <room.h>
inherit ROOM;

void create()
{
	set("short","�η�");
	set("long", @LONG
�ıڶ��Ǹ�������,������ʪ,һ���Ͳ���ʲô�õط�.
������������̹�Ѻ���˵ĵط�.
LONG
	);

	set("exits", ([
		"south" :__DIR__"laofang3",
		"north" :__DIR__"laofang2",
		"west"  :__DIR__"dingfeng7",
		"east"  :__DIR__"laofang4",
  	]));
	create_door("north", "����", "south", DOOR_CLOSED);
	create_door("south", "����", "north", DOOR_CLOSED);
	setup();
}

