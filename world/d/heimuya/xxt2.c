// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","�������");
	set("long", @LONG
����һ��������,������ӡ,���������ܷ�æ��·,
·��ϡϡ�����ĳ��ż���С��.�����ͨ������̲ 
��Ψһ��һ�����
LONG
	);

	set("exits", ([
		"northwest" :__DIR__"xxt3",
                "east" :__DIR__"xxt1",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

