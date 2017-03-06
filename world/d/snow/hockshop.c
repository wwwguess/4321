// Room: /d/snow/hockshop.c

#include <room.h>

inherit HOCKSHOP;

void create()
{
	set("short", "��ǵ���");
	set("long", @LONG
����һ���еȹ�ģ�ĵ��̣��ϾɵĹ�̨�Ϸ���һ��ľ��(sign)����
��Ĺ��߲��Ǻ����������ĳ��ڱ�һ����ɫ���������������С�����Ī
�롹��������������һ��ľ����(door)ͨ����֡�
LONG
	);
	set("item_desc", ([
		"sign": @TEXT
�����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ�
���Ŀ���������䵱(pawn)������(sell,value)���ֻ��ͭǮ���������ƽ�һ��ͨ�á�
Ҫ���(redeem)����뱣�ֵ�Ʊ������
TEXT
	]) );
	set("exits", ([
		"west" : __DIR__"mstreet3",
		"east" : __DIR__"hockshop2",
	]));
//	set("objects", ([
//		CLASS_D("beggar") + "/master" : 1,
//	]) );

	setup();

	create_door("west", "ľ����", "east", DOOR_CLOSED);
}
