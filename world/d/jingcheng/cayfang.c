// Room: /d/jingcheng/cayfang.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m�����ַ�[2;37;0m");
	set("long", @LONG
�����ǳ�����һ�����������ֳ�������ҹĻ���ٺ������
�������֡����������Ŀ����д�ٹ��ˣ��������������ã�
�˼����ĵ����ӣ������Ⱥ�ı�ʿ����ʱҲ�ܿ���һЩ����
�ʹ���ɮ�˻��ʿ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"yfangup",
  "west" : __DIR__"baih6",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/youke" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
