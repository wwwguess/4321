#include <room.h>

inherit ROOM;

void create()
{
   set("short", "���᷿");
	set("long", @LONG
����붫�᷿�����ٴ��ĵ��������ɺ�ë̺��������������Ǯ
��������ʯ���Ǯ����������ɫ��Ǯ�������졣������һ��÷��ʽ
����С������������ƿ���㱸������һ���ϵ��᷿��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"eroad1",

]));

      set("objects", ([
          __DIR__"npc/servant" : 1,
          __DIR__"npc/elon" : 1 ]) );
    create_door("west","���η���","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
