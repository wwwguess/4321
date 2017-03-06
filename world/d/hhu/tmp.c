// Room: /d/hhu/hohai-room.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�Ӻ���");
	set("long", @LONG
�Ӻ����ǺӺ���ѧ�ڵĴ���֮һ
    ���������ڴ˰칫��
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hhupath2",
  "up" : __DIR__"hohai-room2f",
]));
	set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/Pro.Zhang" : 1,
]));
       create_door("north","������","south",DOOR_CLOSED);

	setup();
}
