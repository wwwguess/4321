// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��С��");
	set("long", @LONG
�����һ����,�����ʯ�������,
ɽʯ�ϲ�����̦޺,ʪ������,һ����֪
��ʯͷ������ˮԴ
LONG
	);

	set("exits", ([
		"north" :__DIR__"shanjiao7",
                "south" :__DIR__"shanjiao5",
	]));
	
	set("objects",([
                __DIR__"npc/jiao_zhong2" : 2,
        ]));

	set("outdoors", "heimuya");
	setup();
}

