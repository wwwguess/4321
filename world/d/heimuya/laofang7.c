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
		"south" :__DIR__"laofang9",
		"north" :__DIR__"laofang8",
		"west"  :__DIR__"laofang4",
		"east"  :__DIR__"laofang10",
  	]));
	create_door("north", "����", "south", DOOR_CLOSED);
	create_door("south", "����", "north", DOOR_CLOSED);
	setup();
}

