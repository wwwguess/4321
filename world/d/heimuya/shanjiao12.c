// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��С��");
	set("long", @LONG
	·������Ǹ�������,�ұ����޾���Ԩ,
�����ľ���ս,С����������˹�ȥ	
LONG
	);

	set("exits", ([
		"northup" :__DIR__"shanjiao13",
                "southdown" :__DIR__"shanjiao11",
	]));
	
	set("outdoors", "heimuya");
	setup();
}

