// Room: /d/choyin/e_street1.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
    �����������سǵĶ���֣����߲�Զ����ʯ̨����Զ�������ġ���
���ء������������һֱͨ�������ţ��ֵ�������������լ��������
�˽�ϡ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tree_tomb",
  "east" : __DIR__"e_gate",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
