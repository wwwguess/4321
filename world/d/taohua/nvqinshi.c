// Room: /d/shaolin/nvqinshi.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "Ů����");
	set("long", @LONG
������Ů���ҡ���ǽһ����ż���ľ��������
������ı��죬����һ������˯��
LONG
	);
	set("sleep_room",1);

	set("exits", ([
		"north" : __DIR__"yushimen",
		
	]));

	setup();
        replace_program(ROOM);
}



