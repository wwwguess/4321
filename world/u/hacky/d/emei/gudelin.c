// Room: /d/emei/gudelin.c ������ �ŵ���


#include <room.h>
inherit ROOM;


void create()
{
	set("short", "�ŵ���");
	set("long", @LONG
����һƬ���ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ
��ľ������΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ�
���Ǿ��ѵ��������ڡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"bailongdong",
		
	]));

//	create_door("south","ľ��","north",DOOR_CLOSED);

	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}


void init()
{
	this_player()->set_temp("bamboo/count", 0);
}


int valid_leave(object me, string dir)
{

	if (dir == "southwest" ) me->add_temp("bamboo/count", 1);
	else if (dir == "south") me->delete_temp("bamboo/count", 1);
	else 			 me->add_temp("bamboo/count", -1);

	return ::valid_leave(me, dir);
}


