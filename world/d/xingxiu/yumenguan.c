
inherit ROOM;

void create()
{
	set("short", "���Ź�");
	set("long", @LONG
�������˿��֮·�����һ���ؿ���.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" :__DIR__"silk3",
	"south" : __DIR__"rdhtoym0",
]));

	setup();
	replace_program(ROOM);
}
