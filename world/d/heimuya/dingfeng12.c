// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","�㳡");
	set("long", @LONG
һ����㳡,ȫ�ɺ������̳�,����ܴ�,һ���ǳ���ΰ�Ľ���
�����ڹ㳡��,�����������̵�Ȩ������----"�ɵµ�"��.
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

