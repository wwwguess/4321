#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLU"��������"NOR);
	set("long", @LONG

LONG
	);

	set("exits", ([
 "west" :__DIR__"xizhimen",
 "east" :__DIR__"xchjie2",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

