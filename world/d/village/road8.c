// Room: /d/village/road8.c

inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
С·�����������ݺ��������ǵ������ϲƵ�լԺ��������һƬ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road9",
  "north" : __DIR__"road7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
