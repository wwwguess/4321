// Room: /d/suzhou/qxku.c
// by dwolf
//97.11.4 
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"��е��"NOR);
	set("long", @LONG
	����Ƿ��ھֵ�����ʹ�õ���е�ĵط������񽣣��񵶡�
LONG
	);

	set("exits", ([
		"east" : __DIR__"biaoju",
	]));

	set("objects", ([
		__DIR__"npc/obj/zhudao" : 2,
		__DIR__"npc/obj/zhujian" : 2,
	]));

	setup();
	replace_program(ROOM);
}

