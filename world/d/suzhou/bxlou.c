// bxlou.c
//by dwolf
          
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"���ɾ�¥"NOR);
	set("long", @LONG
	���ɾ�¥���Ƿǳ�������һ�Ҿ�¥������ʷ�ƾã��������á���������������
������������ϼ��������������������ˣ����Ĵ������������Ѿ�û����λ�ˡ�
LONG
);
	set("exits", ([
		"up" : __DIR__"bxlou2",
		"south" : __DIR__"wroad1",
		"east" : __DIR__"nroad1",
	]));                               
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
		__DIR__"npc/ren" : 2,
	]));
	setup();
	replace_program(ROOM);
}
