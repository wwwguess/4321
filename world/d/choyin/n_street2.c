// Room: /d/choyin/n_street2.c

inherit ROOM;

void create()
{
	set("short", "���ִ��");
	set("long", @LONG
������������һ�����Ľֵ��ϣ���������������ͨ�ϱ����ŵĸ�
�ִ�֣��ֵ����������ϱ����죬����ԶԶ�ؿ����������ŵ�ʯ��¥��
�ϱ߲�Զ�����������س������ĵر꡸�����ء�����Ķ�����һ������
¥�ľƹݣ���������Զ����������Ҧ��ׯ�����ϲ�ʱ�з������䴩��
������ʮ�����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"n_street3",
  "north" : __DIR__"n_street1",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
