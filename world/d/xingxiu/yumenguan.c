
inherit ROOM;

void create()
{
	set("short", "玉门关");
	set("long", @LONG
这里就是丝绸之路的最后一个关口了.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" :__DIR__"silk3",
	"south" : __DIR__"rdhtoym0",
]));

	setup();
	replace_program(ROOM);
}
