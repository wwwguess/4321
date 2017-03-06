// Room: /d/snow/school1.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "������ݴ���");
	set("long", @LONG
��������վ��һ���լԺ����ڣ���ֻ�޴��ʯʨ�����ڴ��ŵ���
�࣬һ����ߺ���뵶����ײ��������Ժ���д�����ͨ����������������
����������µĺ������ڲ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/snow/mstreet1",
  "east" : "/d/snow/school2",
]));
	set("outdoors", "snow");
	set("objects", ([
		__DIR__"npc/guard": 1 ]) );

	create_door("east", "�������", "west", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
