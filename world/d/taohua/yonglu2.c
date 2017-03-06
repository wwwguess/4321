// Room: /d/taohua/yonglu2.c

inherit ROOM;

void create()
{
	set("short", "甬路");
	set("long", @LONG
只见乔木修竹，苍翠蔽天，层峦奇幽，静窈幽深。一条青石小径伸
向前方花丛深处。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "north": __DIR__"houhuayuan",
  "south" : __DIR__"yonglu1",
 
]));
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
