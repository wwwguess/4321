// Room: /d/choyin/rockpath1.c

inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
��·����ʯ����ͩ��ɽ.������ϡ��,�ѿ챻é����û.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
              "northdown" : __DIR__"rockpath2",
              "southup" : __DIR__"rockyu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
