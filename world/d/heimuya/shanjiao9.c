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
		"northup" :__DIR__"shanjiao10",
                "westdown" :__DIR__"shanjiao8",
	]));
	
	set("outdoors", "heimuya");
	setup();
}

