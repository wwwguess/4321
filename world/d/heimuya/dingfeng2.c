// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","������¥");
	set("long", @LONG
	һ��������ľ޴���¥,��¥���ĸ�����"�󱻲���"�����������
	������Ȼ��.
LONG
	);

	set("exits", ([
		"north" :__DIR__"dingfeng3",
                "south" :__DIR__"dingfeng1",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

