// Room: /d/village/road9.c

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
��ֻС�����䵽��֦�ϣ�ߴߴ�����и���ͣ�����ǵļҿ����ڸ�����
��С·��������һƬ�����͵ĵ������ũ�������æµ�������ǵ�����
�ϲƵ�լԺ���ѵ�һ�������ķ��Ӳ������ر��ݻ���ֻ���������ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"road8",
  "west" : __DIR__"field",
  "east" : __DIR__"lordhouse1",
]));
	create_door("east","���ϲƼҴ���","west",DOOR_CLOSED);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
