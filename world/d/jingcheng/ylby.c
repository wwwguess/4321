// Room: /d/jingcheng/ylby.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m���־�Ӫ[2;37;0m");
	set("long", @LONG
���־�Ӫ���Ȼ�ȱ𴦱�Ӫ����ɭ�ϡ�����һ��ʿ�����ڲ���������
����ı����ڴ�׮�����������ſڴ���Ա������������Ѳ�ӡ�������
������׵�������ȥ�������������ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"bdj2",
]));
	set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/fu-j" : 3+random(3),
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
