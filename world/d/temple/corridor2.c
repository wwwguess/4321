// Room: /u/k/karrimor/temple/corridor2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������������һ��������, ��������һ����ľ���յ��쾮, ����
���ߵ�Բ�ι��žͿ��Իص���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" : __DIR__"corridor6",
     "east" : __DIR__"temple1",
]));

	setup();
	replace_program(ROOM);
}
