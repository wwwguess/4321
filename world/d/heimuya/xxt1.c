// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","�������");
	set("long", @LONG
����һ�����Ļ��������������Գ������Ӳݺ�С��֮���, 
�����൱�Ļ���. �����ͨ������̲��Ψһ��һ�����
LONG
	);

	set("exits", ([
		"west" :__DIR__"xxt2",
                "southeast" :__DIR__"sancha",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

