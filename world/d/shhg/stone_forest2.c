// Room: /d/canyon/stone_forest2.c

inherit ROOM;

void create()
{
	set("short", "��ʯ����·");
	set("long", @LONG
��ѹ�춥��������ɣ�Ψ������������������������Ĳ�Զ��
��һ���ڣ���ʯ�߰ߣ�Ю������ɫ��Բ�㣬���ǰ�ɫ�������������
��������ʵľ�ɫ�ڴ�������ȫ�������ˣ��򶫲����ǻص�·�ڵ�·
�������������ֱֱ���������̽����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"stone_forest3",
		"east" : __DIR__"stone_forest1",
]));

	setup();
	replace_program(ROOM);
}
