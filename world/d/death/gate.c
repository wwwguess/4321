// Room: /d/death/gate.c

inherit ROOM;

void create()
{
	set("short", "[1;37m���Ź�[2;37;0m");
	set("long", @LONG
�������������������ڡ����Źء���������ǰ������һ���ߴ��
��ɫ��¥������������޿�������ж�ǰ������Ϊһ�����Źؾ��޷���
�������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"bridge",
		"north" : __DIR__"gateway",
]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/wgargoyle" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
