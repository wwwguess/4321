// Room: /d/death/spath1.c

inherit ROOM;

void create()
{
	set("short", "ǽ��С·");
	set("long", @LONG
����һ��������ǽ��С·��������һ���ߴ�Ρ��ĳ�¥����¥ǰ��
һ��������ʯ�ţ��������ģ����Ӱ�����ж��߽����š�С·��������
�����һƬ�ӵء�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"gateway",
]));
	set("outdoors", "death");

	setup();
	replace_program(ROOM);
}
