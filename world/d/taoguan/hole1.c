
inherit ROOM;

void create()
{
	set("short", "洞内");
	set("long", @LONG
洞里黑暗潮湿。你心里的不祥感觉越来越重。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hole2",
  "south" : __DIR__"hole",
]));
	setup();
        replace_program(ROOM);
}
