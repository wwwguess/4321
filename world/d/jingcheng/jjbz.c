// Room: /d/jingcheng/jjbz.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m�ּҹ���������[2;37;0m");
	set("long", @LONG
�ּҹ��������ɼ����ֵ�����ʼ����ʮ������Ҳ�ڳ�����������Ե��
�ᵽ�������ӣ�����������˶���˵�ּҵĵ�һ���������ɾ���ʮ
���Ű������������У������˳Կ͡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ql2",
  "north" :__DIR__"chuf",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jia" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
