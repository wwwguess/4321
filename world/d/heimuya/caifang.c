// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","柴房");
	set("long", @LONG
	普普通通的一间柴房,堆满了柴草,这儿显然是严禁火烛的
LONG
	);

	set("exits", ([
		"west"  :__DIR__"dingfeng5.c",
	]));

    set("sleep_room",1);
	setup();
	replace_program(ROOM);
}

