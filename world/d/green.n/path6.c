// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ��ƽ����ʯ��·, ������Լ���Կ�����������ĳ���, ����
��������������;�ĵ�·. ������ͨ��ɽ�µ�·, ��������Կ���һЩ
������, ���Ǵ�ׯ֮���. �ϱ߿�ȥ��һƬ������.

LONG
	);
    set("exits", ([
    "west" : "/d/snow/crossroad",
    "east" : __DIR__"path5",
]));
	set("no_clean_up", 0);
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
