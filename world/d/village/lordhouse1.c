// Room: /d/village/lordhouse1.c

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "������ǰԺ");
	set("long", @LONG
�������ϲƵļ��ƺ��������ϲƵ���������Ӧ����ɫ�ĵͰ�ԺǽΧ��
�������ӡ����ϲƼҵ�ǰԺ���м���һ�ô������쿪��֦Ҷ�ڳ�һ��Ƭ
�������������Ӷ������Ϸ���ǰԺ��������һ����ڵĴ��š�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lordhouse3",
  "west" : __DIR__"road9",
  "east" : __DIR__"lordhouse2",
]));
	create_door("west","���ϲƼҴ���","east",DOOR_CLOSED);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
