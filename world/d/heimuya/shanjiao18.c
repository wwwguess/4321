// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��ʯ��");
	set("long", @LONG
һ����ʯ�ſ����Կ������д���������"�ĳ����"
������"����Ӣ��",�������"���¹���"�ĸ������
LONG
	);

	set("exits", ([
		"north" :__DIR__"shanjiao19",
                "south" :__DIR__"shanjiao17",
	]));
	
	set("outdoors", "heimuya");
	setup();
}

