// Room: /d/waterfog/east_2f.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ˮ�̸󶫲����Ķ�¥�����ڲ��������߽������������ֻ��
һ��Լ�ߡ��˳߿���ߵ�����¥�����������š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"forehall",
		"down" : __DIR__"eaststair",
	]));
	set("objects", ([
		__DIR__"npc/elite_guard": 2
	]) );

	set("waterfog_guard_dir", "west");
	setup();
	replace_program(ROOM);
}
