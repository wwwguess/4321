// Room: /d/suzhou/lwchang.c
// by dwolf
//97.11.4 
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"���䳡"NOR);
	set("long", @LONG
�����ھֵ�������ĵط��������ھֵ����������䣬һ����ͷ��һ��ָ�㡣���ӵĺ�
�����졣������ĵ��������������޶á��㲻�ɶ����ǵľ�ͷ�ж��ˡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"biaoju",
		"north" : __DIR__"bjdting",
	]));

	set("objects", ([
		__DIR__"npc/fighter2" : 2,
		__DIR__"npc/biaotou" : 1,
	]));

	setup();
	replace_program(ROOM);
}

