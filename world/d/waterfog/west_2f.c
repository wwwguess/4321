// Room: /d/waterfog/west_2f.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ˮ�̸��������Ķ�¥�����ڲ��������߽������������ֻ��
һ��Լ�ߡ��˳߿���ߵ�����¥�����������š�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"weststair",
		"east" : __DIR__"forehall",
	]));
	set("objects", ([
		__DIR__"npc/elite_guard": 2
	]) );

	set("waterfog_guard_dir", "east");
	setup();
	replace_program(ROOM);
}
