// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��С��");
	set("long", @LONG
�ò����׳���һ����,�㳤����һ����,Ĩ��Ĩ��,����ǰ��.
LONG
	);

	set("exits", ([
		"northup" :__DIR__"shanjiao8",
                "south" :__DIR__"shanjiao6",
	]));
	
	set("outdoors", "heimuya");
	setup();
}

