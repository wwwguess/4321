// Room: /d/choyin/solidpath1.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
�����̾͵�С·.������,��Ţ����.���Ͼ���ɽ��.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"e_gate",
  "south" : __DIR__"rockpath2",
  "north" : __DIR__"solidpath2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
