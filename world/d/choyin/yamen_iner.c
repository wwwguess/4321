// Room: /d/choyin/yamen_iner.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������ү�������, Ʒ��, ��ʫ, ����֮��; �����ľ�......
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yamen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
