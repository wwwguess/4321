// Room: /d/jingcheng/mzh3.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m��լ[2;37;0m");
	set("long", @LONG
�⻧�˼��ڳ�������Ҳ��Ƚϸ�ԣ���ˡ������˳��꾭�����⣬��
���ڼ����ּ�����ͬ�����Ǵ�����˼�һ�������﹩���Ϻ�����
�͹���ү������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"baih3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yahuan" : 2,
        __DIR__"npc/oldwoman" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
