// Room: /d/hhu/roadtocenter1.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����·ͨ������������ģ��ǿ��ǺӺ���ѧ�е�ͨѶ��Ŧ����
    �����Ͽ��Կ�������������ĵĴ���(door),������������.
    ���ܷ羰������
LONG
	);
        set("item_desc",([
        ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hhucenter",
  "northdown" : __DIR__"roadtocenter",
]));
	set("objects", ([ ]));
        create_door("south","������","north",DOOR_CLOSED);
	set("no_clean_up", 0);

	setup();
}
