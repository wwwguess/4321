// Room: /d/new_taohua/nanqinshi.c
// Date: YZC 96/01/19
//write by lysh

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������ҡ���ǽһ����ż���ľ��������
������ı��죬����һ������˯��
LONG
	);
	set("sleep_room",1);

	set("exits", ([
		"south" : __DIR__"yushimen",
		
	]));

	setup();
        replace_program(ROOM);
}



