// Room: /d/jingcheng/gzj.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m���Ӽ�[2;37;0m");
	set("long", @LONG
���Ӽ��ǹ��������߼��˲ŵĵط�����ͥ��ѧ���Ũ�������ﲻʱ
���Կ�������������ѧ��ģ�����˴���������ʲô���⣬����һЩ
������������üͷ�Ҵ��߹���������˼����ʲô���⡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ndj2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiucai" : 2,
        __DIR__"npc/jiaoshou" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
