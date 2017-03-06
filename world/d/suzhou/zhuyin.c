// Room: /d/suzhou/zhuyin.c
//by dwolf
//97.11.4 

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"��Ӫ"NOR);
	set("long", @LONG
	������������Ӫ���������佫�������Ǵ��¹�Ӣ�������Ǵ����ţ��ϱ���
�����⣬һ�����ŵ�סȥ·��
LONG
	);

	set("exits", ([
		"south" : __DIR__"wqku",
		"north" : __DIR__"yinzhang", 
		"east" : __DIR__"mapeng",
	]));       
	create_door("north", "bulian", "south", DOOR_CLOSED);
	create_door("south", "����", "north", DOOR_CLOSED);

	set("objects", ([
                 __DIR__"npc/mgying" : 1,
                "/obj/npc/wujiang1"+random(3) : 2,
                "/obj/npc/wujiang1"+random(3) : 2,
	]));

	setup();
}

