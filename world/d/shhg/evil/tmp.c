// Room: /d/canyon/evil/tmp.c

inherit ROOM;

void create()
{
	set("short", "��ħ�����");
	set("long", @LONG
�����У���������:P
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"up" : "/d/canyon/fantasy1",
]));

	setup();
	replace_program(ROOM);
}
