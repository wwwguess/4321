// Room: /d/temple/broom2.c

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
����¥��, �����㿴��һ������ʦ�Ļ�����ڶ����ǽ��, ����
���·�����һ�Ÿ����첼������, ��������ط���éɽ������ؼ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : "/d/temple/book_room1",
]));

	setup();
	replace_program(ROOM);
}
