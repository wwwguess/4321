// Room: /d/jingcheng/dchjie4.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m��������[2;37;0m");
	set("long", @LONG
һ����������ʯ��·��·����һ����Ӫ������������ʿ�ǲ�����������
�����Ѿ����Կ�����¥���������˲��ϣ��Ƕ��Ĳ�ũһ�㶼��������
��ʱ���߲��������У��ֳ�Ϧ����ɽǰ�ϻؼ��С�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/youxia" : 1,
]));
	set("outdoors", "city");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"bingying",
  "west" : __DIR__"dchjie3",
  "east" : __DIR__"dchjie5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
