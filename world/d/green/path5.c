// Room: /d/green/path5.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ��ƽ����ʯ��·, ������Լ���Կ�����������ĳ���, ����
��������������;�ĵ�·. ������һ����С����ʯ·ͨ������. ������
һ��ʯ��, �ԱߵĿյض���һЩʯ��. �ϱ߿�ȥ��һƬ������. ʯ��·
����������.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/green/path6",
  "north" : "/d/green/path4",
  "east" : "/d/green/station0",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
