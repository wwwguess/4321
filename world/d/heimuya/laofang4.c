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
		"south" :__DIR__"laofang6",
		"north" :__DIR__"laofang5",
		"west"  :__DIR__"laofang1",
		"east"  :__DIR__"laofang7",
  	]));
	create_door("north", "����", "south", DOOR_CLOSED);
	create_door("south", "����", "north", DOOR_CLOSED);
	setup();
}

