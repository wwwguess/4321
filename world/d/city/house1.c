// Room: /d/city/house1.c

inherit ROOM;

void create()
{
	set("short", "�շ���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"street11",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
