// Room: /d/jingcheng/jwby.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m������Ӫ[2;37;0m");
	set("long", @LONG
����פ����������������������ϵİ�ȫ������������ڳ��ⰲӪ��
����פ������������˴ӽ��������������������в�֮ʿ��ƽ���Ｘ
Ա�����������ڱ�����ϣ���պ���������ս����һ�����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"bdj1",
]));
/* set("objects", 
        __DIR__"npc/fu-j": 3+random(3),
]));
 */
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
