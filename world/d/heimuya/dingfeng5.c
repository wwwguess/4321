// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��ʯ���");
	set("long", @LONG
	һ�������ɵ���ʯ���,·����Ƿ���,·�ұ��ǲ�
LONG
	);

	set("exits", ([
		"west"  :__DIR__"fangtang",
		"east"  :__DIR__"caifang",
		"north" :__DIR__"dingfeng6",
                "south" :__DIR__"dingfeng4",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

