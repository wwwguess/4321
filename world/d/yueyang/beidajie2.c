// Room: /city/beidajie2.c
// YZC 1995/12/04 

#include <ansi.h>

inherit ROOM;

void create()
{
       set("short", BLK "�����" NOR);
	set("long", @LONG
	����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ����⡣
�ϱ��Եúܷ�æ��������һ�������¥�󣬹��š�̫���ŷ硱���������Ŷ�����
��һ�����ң�������¥�����ֲ�������������������ѧʿ���ֱʡ�����������
�����㴹�����Ρ�������һ�����ӵ����������ƣ��Ǿ�������ѧ��֮������
ͬ�����������ˡ�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"south" : __DIR__"beidajie1",
		"west" : __DIR__"wumiao",
		"north" : __DIR__"beimen",
	]));

	setup();
	replace_program(ROOM);
}

