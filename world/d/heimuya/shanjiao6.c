// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","羊肠小道");
	set("long", @LONG
这就是一线天,两块巨石对面而立,
山石上布满了苔藓,湿漉漉的,一看就知
道石头下面有水源
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

