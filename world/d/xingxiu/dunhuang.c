
inherit ROOM;

void create()
{
	set("short", "敦煌");
	set("long", @LONG
这里就是丝绸之路上的重镇敦煌.再往西走就是大沙漠了,从西北
继续走,就是丝绸之路到玉门关的一段了,路更艰险了.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northwest" : __DIR__"rdhtoym0",
	"west" : "/d/road/dhshamo",
	"southeast" : __DIR__"rjygtodh2",
]));

	setup();
	replace_program(ROOM);
}
