// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
������ɽ�ĵ���������,���˰����������˻����ľ��
���������,�Ϳ�����������
LONG
	);

	set("exits", ([
		"north" :__DIR__"shanjiao18",
                "south" :__DIR__"shanjiao16",
	]));
	
	set("objects",([
                __DIR__"npc/jiao_zhong5" : 2,
        ]));

	set("outdoors", "heimuya");
	setup();
}

