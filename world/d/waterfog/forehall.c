// Room: /d/waterfog/forehall.c

inherit ROOM;

void create()
{
	set("short", "��Х��");
	set("long", @LONG
������ˮ�̸��¥����Х����������һ����¶̨�������������ϡ�
�ϡ����ϡ����ȷ�������������ɫ�Ĺ�ʯ(stone)����������һ����
��ͨ����������������ˮ�̸������ӵĴ���ˮɫի��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"west_2f",
		"east" : __DIR__"east_2f",
	]));
	set("objects", ([
		__DIR__"npc/elder5" : 1,
		__DIR__"npc/elder6" : 1,
		__DIR__"npc/elder7" : 1,
	]) );
	setup();
	replace_program(ROOM);
}
