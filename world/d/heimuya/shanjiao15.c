// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
������ɽ�ĵڶ�������,���˰����������˻����ľ��
LONG
	);

	set("exits", ([
		"north" :__DIR__"shanjiao16",
                "south" :__DIR__"shanjiao14",
	]));
	
	set("objects",([
                __DIR__"npc/jiao_zhong4" : 2,
        ]));

	set("outdoors", "heimuya");
	setup();
}

