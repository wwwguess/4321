#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����ɽׯ����");
	set("long", @LONG
��������վ��һ���ׯԺ����ڣ���ǰ��һ���ߴ�ĺ�����ţ�
�ŵ��Ϸ��߹���һ�����ң���������ɽׯ�ĸ����֣�������һ��
Сʯ�š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/yulan/road2",
  "east" : "/d/yulan/yulan",
]));
	set("outdoors", "yulan");

	create_door("east", "�������", "west", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
