// Room: /d/green/path6.c

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
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/snow/crossroad",
  "east" : "/d/green/path5",
"north" :"/d/xinfang/bieshuqu",
]));
	set("no_clean_up", 0);
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
