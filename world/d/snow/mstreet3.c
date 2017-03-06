// Room: /d/snow/mstreet3.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "ѩͤ��ֵ�");
	set("long", @LONG
������ѩͤ��Ĵ�֣�������һ���¾ɵĽ���������������ʲô��
�̣����ǲ�û���κ����ƣ�ֻ��һ����(door)����д��һ�����ġ���
���֣�������һ��ҩ�̣�������ϱ������������졣
LONG
	);

	set("exits", ([
		"south"	: __DIR__"mstreet2",
		"north"	: __DIR__"mstreet4",
		"east"	: __DIR__"hockshop",
		"west"	: __DIR__"herbshop",
	]));
	set("outdoors", "snow");

	setup();

	create_door("east", "������", "west", DOOR_CLOSED);

	replace_program(ROOM);
}
