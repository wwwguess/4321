// Room: /d/choyin/solidpath2.c

inherit ROOM;

void create()
{
	set("short", "��ҰС��");
	set("long", @LONG
��Ұ�е�С·,��ϡ�ɱ�,��������,��֪ͨ��η�.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"cloudpool",
  "south" : __DIR__"solidpath1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
