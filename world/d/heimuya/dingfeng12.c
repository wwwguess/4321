// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","广场");
	set("long", @LONG
一个大广场,全由汉白玉铺成,面积很大,一座非常宏伟的建筑
屹立在广场上,这就是日月神教的权力中心----"成德殿"了.
LONG
	);

	set("exits", ([
		"north" :__DIR__"cdd",
                "south" :__DIR__"dingfeng11",
	]));
	set("objects",([
                __DIR__"npc/jiao_zhong7" : 4,
        ]));


	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

