// Room: /city/dongdajie1.c
// YZC 1995/12/04 

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", GRN "�����" NOR);
	set("long", @LONG
	����һ����������ʯ��ֵ���������ͷ���졣���߲�ʱ�ش�������ײ
�����������������ӡ�������һ�����ӵ�Ժ�ӣ������εĴ����Ϸ�д�š���¹��
Ժ���ĸ��̽���֣��Ծ����������治ʱ�ش���ѧ��������ٴ�Ķ��������ϱ�
��һ���ӻ��̡�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"dongmen",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"shuyuan",
		"south" : __DIR__"yizhan",

	]));

	setup();
	replace_program(ROOM);
}

