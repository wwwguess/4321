//ROOM: /d/suzhou/mapeng.c
//by dwolf
//97.11.4
       
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", "���ǹ�������Ϣ�ĵط��������������ƥ��\n"); 
	set("objects", ([
		__DIR__"npc/obj/horse" : 4,
]));
	set("exits", ([
		"west" : __DIR__"zhuyin",
]));
	setup();
	replace_program(ROOM);
}
