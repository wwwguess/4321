#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����ɽׯǰԺ");
	set("long", @LONG
��������վ��һ���ׯԺ��ǰԺ��������һ���ߴ�ĺ�����ţ�
������һ������ɽׯ�Ĵ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/yulan/yulan_gate",
  "east" : "/d/yulan/yulanhall",
]));

        set("objects", ([
             __DIR__"npc/chicken" :2,
        ]) );


       set("outdoors", "yulan");
       create_door("west", "�������", "east", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
