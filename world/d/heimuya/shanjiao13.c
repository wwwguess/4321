// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
�����ʯ�������,�м��˹��޽���һ������
LONG
	);

	set("exits", ([
		"north" :__DIR__"shanjiao14",
                "southdown" :__DIR__"shanjiao12",
	]));
	
	set("objects",([
                __DIR__"npc/jiao_zhong3" : 2,
        ]));

	set("outdoors", "heimuya");
	setup();
}

