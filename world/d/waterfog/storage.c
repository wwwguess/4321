// Room: /d/waterfog/storage.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
������һ��񷿣�һ��һ�����õĲ�н������ضѷ��ڲ񷿱��࣬
����һ��ͨ��ͨ���������۵����ҡ����Ͽ��Իص�ˮ�̸����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"weststair",
		"east" : __DIR__"servant_room",
	]));
	set("objects", ([
		__DIR__"npc/servant" : 2
	]) );

	setup();
	replace_program(ROOM);
}
