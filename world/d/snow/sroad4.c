// Room: /d/snow/sroad4.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ������ʵ����ʯ���������������������Ļ�ľ������
������ͨ��ˮ�̸����������ν�ѩͤ��ֵ���·�ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/waterfog/sroad1",
  "south" : "/d/snow/sroad3",
]));
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
