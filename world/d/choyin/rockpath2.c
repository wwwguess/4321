// Room: /d/choyin/rockpath2.c

inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
    ��·����ʯ����ͩ��ɽ.������ϡ��,�ѿ챻é����û.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"solidpath1",
  "southup" : __DIR__"rockpath1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
