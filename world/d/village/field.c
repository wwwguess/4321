// Room: /d/village/field.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬ�����͵ĵ�����ӵĳ��Ʒǳ�ϲ�ˣ���Ϊ����������ݺ���
���Ե���Ĺ�Ⱥܷ��㡣����������ܿ���������������де�ɽ�룬��
���ܿ�������ߴ��ݸ߳��������ֵ����ܡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
