// Room: /d/jingcheng/treeflow.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m����������[2;37;0m");
	set("long", @LONG
�������ǽ��꽭���������һ�����ɣ������˴�ܼ���ƱΪӪ��
׬Ǯ��������Ļ��Ʀ��å�������������������Ҳ����㹻֤�ݣ�
�ټ��������޿��κΡ�����Χ��һ���ˣ��������ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"xw1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/liumang" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
