// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��С��");
	set("long", @LONG
����˸���,������ߵ�ɽ�Ʊ��Ǳ߻�Ҫ�ն�,
·������Ǹ�������,�ұ����޾���Ԩ
LONG
	);

	set("exits", ([
		"northup" :__DIR__"shanjiao12",
                "southdown" :__DIR__"shanjiao10",
	]));
	
	set("outdoors", "heimuya");
	setup();
}

