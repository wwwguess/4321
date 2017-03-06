// Room: /d/jingcheng/xw4.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[30m������[2;37;0m");
	set("long", @LONG
�����������ֵ����Σ������������ֺ�������ֵ�ʮ��·�ڡ�
�����Ǿ��ǵĳ������Ǹ����ֵĳ�����ˣ��ʽ���յģ���С��
���ģ��������̾������ڴ˶��ɿ�����
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qigai" : 1,
        __DIR__"npc/liumang" : 1,
	__DIR__"npc/wseller.c" : 1, 
	__DIR__"npc/gseller.c" : 1,
]));
	set("outdoors", "city");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"mzh2",
  "north" : __DIR__"chhgch",
  "east" : __DIR__"xw3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
