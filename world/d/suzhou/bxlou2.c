// bxlou2.c
//by dwolf
          
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"���ɾ�¥��¥"NOR);
	set("long", @LONG
	���ɾ�¥���Ƿǳ�������һ�Ҿ�¥������ʷ�ƾã��������á���������������
������������ϼ��������������������ˣ����Ĵ������������Ѿ�û����λ�ˡ�Զ��
�ļ�����һ���Ͳ��ǳ��ˣ�������ʲô���ܡ�
LONG
);
	set("exits", ([
		"down" : __DIR__"bxlou",
	]));                               
	set("objects", ([
		__DIR__"npc/tianss" : 1,
		__DIR__"npc/tianx" : 1,
]));
	setup();
	replace_program(ROOM);
}
