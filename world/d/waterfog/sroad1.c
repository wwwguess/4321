// Room: /d/waterfog/sroad1.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ������ʵ����ʯ�������������Ѿ�������������ɽ����
ˮ�̸�����ɫ�����ߣ�ӳ��ɽ��ï�ܵķ����֣��Ե�ʮ��ʫ�黭�⣬��
������·�ǽ���ͳ�����Զ��죬�����ø���ƽ���������￪ʼ�Ѿ���
��������ˮ�̸���������Ͻ�ķ�أ���ʹ�ǹٸ�Ҳ���ܹ�����Ƭ������
�������£���������С��һ�㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/snow/sroad4",
  "northwest" : "/d/waterfog/sroad2",
]));
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
