// Room: /d/jingcheng/nchkzh.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m�ϳǿ�ջ[2;37;0m");
	set("long", @LONG
��ҿ�ջ�����������ģ���������ǳ���¡����֮��Ǯ��������
�ǳ�������ο���ŵ���ѡ��¶������߰������ӣ����̾����˵�
�ڴ˽������������ﲻ�����������õ�С�������ػ��д����ķ���
�͡���¥���������������ǿͷ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"nchkzh2",
  "west" : __DIR__"ndj1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer1" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
