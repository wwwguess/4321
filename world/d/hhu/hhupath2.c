// Room: /d/hhu/hhupath2.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���������ںӺ���ѧУ�ڵ��������
    ���Ͽ�����һ����¥: �Ӻ���(hohai-room)
    ���ܷ羰������
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"hohai-room.c",
  "west" : __DIR__"hhupath3",
  "east" : __DIR__"hhupath1",
]));
        create_door("south","������","north",DOOR_CLOSED);

	setup();
        replace_program(ROOM);
}
