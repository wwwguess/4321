#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���幬�᷿");
	set("long", @LONG
����ķ��䣬ȴ�ܸɾ�����������ǽ�Ϲ��ż���ɽˮ����
�����Ǽ��Ŵ�齣�������ʿ���ڴ����������ǽ�Ϲ��ż��ѳ�
�������Կ������Ƕ��Ǻý���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"east" : __DIR__"da_yuan",
]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/reg_taoist" : 5,
                __DIR__"npc/up_taoist" : 1,
]));
	setup();
	replace_program(ROOM);
}
