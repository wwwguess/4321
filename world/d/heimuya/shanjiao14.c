// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��С��");
	set("long", @LONG
һ����С��,�����Ǿ�ʯ,������������
LONG
	);

	set("exits", ([
		"north" :__DIR__"shanjiao15",
                "south" :__DIR__"shanjiao13",
	]));
	
	set("outdoors", "heimuya");
	setup();
}

