// Room: /d/choyin/w_street2.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����������سǵ�����֣����ž���������߼�ʮ���⣬��������
ͨ�������ص������ر꡸�����ء�������������̵꣬������һ�Ҵ��
¥���ϱ�����һ��Ⱦ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"w_street1",
  "east" : __DIR__"w_street3",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
