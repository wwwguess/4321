// Room: /d/heimuya/.c
// write by: dfbb 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","���");
	set("long", @LONG
    ����ͨ�� "������"��������������������������ӵ�
���̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
����·�߿�ʼ��һЩ�����·����˾���.

LONG
	);

	set("exits", ([
		"south" :__DIR__"yidao2",
		"north" :__DIR__"yidao4",

	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

