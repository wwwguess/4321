// Room: /d/graveyard/road1.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ������������С�������������ش���һƬ�����������Ը���
�ݵ�б�£�������ͨ��һ���ȽϿ����Ĵ�·������������һƬ����ڡ�
LONG
	);
	set("outdoors", "graveyard");
	set("exits", ([ /* sizeof() == 1 */
		"northwest" : __DIR__"grave1",
]));

	setup();
	replace_program(ROOM);
}
