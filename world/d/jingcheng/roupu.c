// Room: /d/jingcheng/roupu.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m�ټ����[2;37;0m");
	set("long", @LONG
�����������õģ���ɨ��Ҳ�Ƚϸɾ������̵��ϰ�ԭ���������
Ҳ�����潫��ȥ�������̡������س������˸�С���̡�����
��ʵ���Ӳ��̽�ȱ�������̵�����Ҳ��һ�պù�һ�ա�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"baih4",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/rong" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
