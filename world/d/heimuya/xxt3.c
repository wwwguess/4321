// Room: /d/heimuya/.c
// write by: dfbb 
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
		"west" :__DIR__"xxt4",
                "southeast" :__DIR__"xxt2",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

