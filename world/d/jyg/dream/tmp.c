// Room: /d/canyon/dream/tmp.c

inherit ROOM;

void create()
{
	set("short", "��Ӱ�����");
	set("long", @LONG
�����У���������:P
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : "/d/canyon/fantasy1",
]));

	setup();
	replace_program(ROOM);
}
