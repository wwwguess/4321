// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��ʯ���");
	set("long", @LONG
	һ�������ɵ���ʯ���,·����Ǹ��õ�������,�ұ��ǹ�Ѻ���˵ĵط�
LONG
	);

	set("exits", ([
		"west"  :__DIR__"yst",
		"east"  :__DIR__"laofang1",
		"north" :__DIR__"dingfeng8",
                "south" :__DIR__"dingfeng6",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

