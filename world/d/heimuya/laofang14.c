// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25
#include <room.h>
inherit ROOM;

void create()
{
	set("short","�η�");
	set("long", @LONG
����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ڰ�����ϡ
���Կ�������ƺ��м�����Ӱ��������ת��ͷȥ������������ס
���������ŵص����㡣
LONG
	);

	set("exits", ([
		"south" :__DIR__"laofang13.c",
  	]));
	set("objects", ([
          __DIR__"npc/fanren4" : 1 ]) );

	create_door("south", "����", "north", DOOR_CLOSED);
	setup();
}

