// Room: /d/jingcheng/biaoju1.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m��Զ�ھ�[2;37;0m");
	set("long", @LONG
��Զ�ھֵĴ�ʼ������Ӣ������Զ������Ӣ�������Ѹߣ����Ѳ���
�ʽ����Ƿ��ˡ������ھֵĶ�������������Զ�Ĵ�����������
���ڲ���������СŮ����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dchjie2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiao-sh" : 1,
        __DIR__"npc/biaotou" : 2,
        __DIR__"npc/tz-shou" : 3,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
