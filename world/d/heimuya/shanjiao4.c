// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��С��");
	set("long", @LONG
����һ�������ޱȵ�һ����,�����ʯ�������,
ֻ��һ���з�����������ֻҪ�Ǳ���������,����
���ѹ���ȥ��.
LONG
	);

	set("exits", ([
		"north" :__DIR__"shanjiao5",
                "southdown" :__DIR__"shanjiao3",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

