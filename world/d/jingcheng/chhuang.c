// Room: /d/jingcheng/chhuang.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m������[2;37;0m");
	set("long", @LONG
�����������ʢ������������Ӽ���ƽ����������¡֮�ࡣ����
ǰ��һ���װ����֣���������ĳ��������һλ�ֳ��ʲ���ë��
���й١�һλ��ף��ǰ�ߺ󣬺ʹ�Ҵ����к���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"chhgch",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/miaozhu" : 1,
]));

	setup();
	replace_program(ROOM);
}
