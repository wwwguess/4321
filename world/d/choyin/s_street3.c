// Room: /d/choyin/s_street3.c

inherit ROOM;

void create()
{
	set("short", "���ִ��");
	set("long", @LONG
�����������سǵĸ��ִ�֣�������һ����̨��̨�ϱ��������ġ�
�����ء�������������Ͼ��������������ֵĽֵ����������������̷�
��Ҳ��࣬��Ķ��ߺ����߶���ʯ��յأ�ƽ�����м����ڴ˴�������
�������������Ǽ���ˮй��ͨ�����ִ�������Ǹ�·�ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"s_street2",
  "north" : __DIR__"tree_tomb",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
