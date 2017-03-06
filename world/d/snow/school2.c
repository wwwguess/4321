// Room: /d/snow/school2.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "������ݽ�����");
	set("long", @LONG
��������վ��һ�����Ľ������У�����������ɫ��ϸɰ�������
��������Ŭ���ز�������������һ��ߴ�ı������������������ʦ��
����Ϣ�Ĵ�����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
//  "south" : "/d/snow/zlroom",
  "north" : "/d/snow/weapon_storage",
  "west" : "/d/snow/school1",
  "east" : "/d/snow/schoolhall",
]));
	set("objects", ([ /* sizeof() == 2 */
  "/d/snow/npc/trainee" : 6,
  "/d/snow/npc/fist_trainer" : 1,
]));
	set("outdoors", "snow");

	create_door("west", "�������", "east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
