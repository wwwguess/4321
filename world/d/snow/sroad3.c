// Room: /d/snow/sroad3.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ������ʵ����ʯ���̳ɵĴ����·�ϳ���ĺۼ��Ѿ���·
��������һ�������Եİ��ۣ�������һ����С�Ľֵ�ͨ��ѩͤ�򣬴�·
�����������ɴ�ˮ�̸������ϴ�����ʯ������ͨ�����ؾ����صص���
�չء�
LONG
	);
    set("exits", ([ /* sizeof() == 3 */
  "southwest" : "/d/canyon/road",
  "north" : "/d/snow/sroad4",
  "east" : "/d/snow/sroad2",
]));
	set("outdoors", "snow");
	set("objects", ([
		__DIR__"npc/crazy_dog": 1 ]) );

	setup();
	replace_program(ROOM);
}
