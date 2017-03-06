// ROOM: /d/suzhou/wqku.c
//by dwolf
//97.11.4 

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", MAG"������"NOR);
	set("long", @LONG
	�����Ǳ����⣬�������������������ۻ����ҡ��������������󵶡�������
�ڰ����̵����̽����̹�����ɫ�����ı���Ӧ�о��У���һʱ��֪����ʲô�á�
LONG
	);

	set("exits", ([
		"north" : __DIR__"zhuyin",
	]));                 
	set("objects", ([
		__DIR__"npc/obj/tiejia" : 1,
		__DIR__"npc/obj/gangdao" : 1,
		"/clone/weapon/fangtianji" : 1,
                "/clone/weapon/xiangmochu" : 1,
		"/clone/weapon/yinqiang" : 1,  
]));

	create_door("north", "����", "south", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}

