// Room: /d/village/road5.c

inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
��ʯС·������ֳ�������һ�������������죬��һ���������棬��
����һ���ʻ�ʢ����С��԰���ŵ������㣬�㲻���Ŀ�����������ңԶ
���������Ⱥɽ��������һƬ�����С�ĺ�����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road6",
  "north" : __DIR__"littlegarden",
  "southdown" : __DIR__"road7",
  "east" : __DIR__"road4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
