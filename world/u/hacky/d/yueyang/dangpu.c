// Room: /d/snow/hockshop.c

#include <room.h>

inherit HOCKSHOP;

void create()
{
	set("short", "��¡����");
	set("long", @LONG
����һ���еȹ�ģ�ĵ��̣��ϾɵĹ�̨�Ϸ���һ��ľ��(sign)����
��Ĺ��߲��Ǻ�����������һ��ľ����ͨ����֡�
LONG
	);
	set("item_desc", ([
		"sign": @TEXT
�����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ�
���Ŀ���������䵱(pawn)������(sell)���ֻ��ͭǮ���������ƽ�һ��ͨ�á�
Ҫ���(retrieve)����뱣�ֵ�Ʊ������
TEXT
	]) );
	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));
//	set("objects", ([
//
//	]) );

	setup();
}
