// Room: /d/choyin/n_gate.c

inherit ROOM;

void create()
{
	set("short", "柳林");
	set("long", @LONG
      荒野之中, 一片茂密的柳树, 遮没了东行的小路. 南面, 不远处
一座宁静的小城, 就是乔阴县了. 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west"  : "/u/cloud/sunhill/road1",
		"south" : __DIR__"n_gate",
	]));
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
