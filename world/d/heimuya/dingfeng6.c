// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��ʯ���");
	set("long", @LONG
	һ�������ɵ���ʯ���,������һ�����䳡��
LONG
	);

	set("exits", ([
		"north" :__DIR__"dingfeng7",
                "south" :__DIR__"dingfeng5",
		 "east" :__DIR__"wgm3",
	]));
	set("objects",([
                __DIR__"npc/jiao_zhong" : 2,
        ]));


	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

