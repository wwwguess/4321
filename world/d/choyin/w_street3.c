// Room: /d/choyin/w_street3.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����������سǵ�����֣����߲�Զ����ʯ̨����Զ�������ġ���
���ء������������һֱͨ�������ţ��ֵ������������̵꣬������
�������ò����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"nw_street",
  "west" : __DIR__"w_street2",
  "east" : __DIR__"tree_tomb",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
