// Room: /d/jingcheng/baih3.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m�׻����[2;37;0m");
	set("long", @LONG
  ������������ֵı��Σ�������һ����ݣ�����ǽҲ�����������
������ȭ���Ϸ���������ֺ������ֵ�ʮ��·�ڡ�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qinshi" : 1,
]));
	set("outdoors", "city");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"xw7",
  "east" : __DIR__"mzh3",
]));

	setup();
}
