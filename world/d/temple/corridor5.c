// Room: /u/k/karrimor/temple/corridor7.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������Χ�����쾮�Ļ�����, ������������������, �ϱ߾�
���쾮, ��Ҳ������߹�ȥ���ͻ�, ɢɢ�ġ�����ı���, �߹�����
����ľ�ž��Ǻ��, Ҳ��éɽ�ɹ���������������λ�ĵط���
LONG
	);
     set("item_desc", ([
         "door": (: this_object(), ({ "look_door", "north"}) :),
     ]));
	set("exits", ([ /* sizeof() == 3 */
     "west" : __DIR__"corridor4",
     "east" : __DIR__"corridor3",
     "south" : __DIR__"inneryard",
     "north" : __DIR__"temple2",
]));

     create_door("north", "����ľ��", "south", DOOR_CLOSED);
	setup();
}
