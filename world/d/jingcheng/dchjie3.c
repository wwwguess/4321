// Room: /d/jingcheng/dchjie3.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32mʮ��·��[2;37;0m");
	set("long", @LONG
�����Ƕ��Ŵ�ֺͰ׻���ֵ�ʮ��·�ڡ�һֱ���߿��Ե���
�ǵĶ��š�����һֱͨ�������ģ�ԶԶ��ȥ����¥�����ɼ���
����������������Ҳ������
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/youxia" : 1,
]));
	set("outdoors", "city");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"baih1",
  "south" : __DIR__"baih4",
  "west" : __DIR__"dchjie2",
  "east" : __DIR__"dchjie4",
]));

	setup();
	replace_program(ROOM);
}
