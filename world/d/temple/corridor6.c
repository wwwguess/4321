// Room: /u/k/karrimor/temple/corridor6.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������һ������֮��, �������ϱ�����, ���˷ֱ����������
����������һ�����ݷ��յ��쾮, ������һ���������ķ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
     "south" : __DIR__"corridor2",
     "north" : __DIR__"corridor4",
     "east" : __DIR__"inneryard",
]));

	setup();
	replace_program(ROOM);
}
