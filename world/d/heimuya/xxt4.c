// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","�������");
	set("long", @LONG
���������̲�Ѿ�����һ�����,ԶԶ�ؾͿ���������ˮ��,
·�ߵ�ɽ��ҲԽ��Խ�ն�.�������в�����Щ�㷲���
LONG
	);

	set("exits", ([
		"west" :__DIR__"xxt5",
                "east" :__DIR__"xxt3",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

