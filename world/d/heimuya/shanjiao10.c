// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��С��");
	set("long", @LONG
    �����С·���û������̵�,�������ߵö���,
Ҳ��ĥ�ù������,·�ߴ�ݲ���,��������.

LONG
	);

	set("exits", ([
		"northup" :__DIR__"shanjiao11",
                "southdown" :__DIR__"shanjiao9",
	]));
	
	set("outdoors", "heimuya");
	setup();
}

