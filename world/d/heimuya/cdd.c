// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25
#include <room.h>
inherit ROOM;

void create()
{
	set("short","�ɵµ�");
	set("long", @LONG
����ĸ����ɸߵĺ����������ذ������ɰ���ʯ�̳ɡ�
����һ������Ĵ���,��������ʮ����,��ȴ����������
���˱˶˸���һ��.
LONG
	);

	set("exits", ([
		"south" :__DIR__"dingfeng12",
		"north" :__DIR__"xiaowu",
	]));

	set("objects",([
		 __DIR__"npc/yanglianting" :1,
		 __DIR__"npc/jiao_zhong6" :4,

        ]));
        create_door("north", "����", "south", DOOR_CLOSED);
	setup();
}

