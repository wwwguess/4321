// Room: /d/choyin/s_street2.c

inherit ROOM;

void create()
{
	set("short", "���ִ��");
	set("long", @LONG
�����������سǵĸ��ִ�֣�����һ������������������ۼ�Ļ���
�������������ľ�¥������¥�������������سǵĸ��̴�ֳ�����¥
���磬������Բ�����ڵ������ž���Ҳ����������Ⱦƣ�������һ��
������ʯ�ٵ���ͨ���ظ����ţ��ֵ������������ֵ����Ź㳡��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"s_street3",
  "south" : __DIR__"s_street1",
  "east" : __DIR__"hotel1",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
