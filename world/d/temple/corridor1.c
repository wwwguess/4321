// Room: /u/k/karrimor/temple/corridor1.c

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
     "west" : __DIR__"temple1",
     "north" : __DIR__"corridor7",
]));

	setup();
	replace_program(ROOM);
}
