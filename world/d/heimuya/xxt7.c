// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��С��");
	set("long", @LONG
����ɽ�ƶ���,ɽʯ��Ϊ��ɫ,ԶԶ��ȥ,ȫ��
Ѫ��֮ɫ.·ҲԽ��Խխ��·�ߵ�ɽ��ҲԽ��Խ��
��.�������в�����Щ�㷲���
LONG
	);

	set("exits", ([
		"northwest" :__DIR__"shanjiao1",
                "east" :__DIR__"xxt6",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

