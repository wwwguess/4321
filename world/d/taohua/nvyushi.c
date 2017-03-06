// Room: /d/new_taohua/nvyushi.c

inherit ROOM;

void create()
{
	set("short", "≈Æ‘° “");
	set("long", @LONG
         ≈Æ‘° “
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "out" : __DIR__"yushimen",
  "east": __DIR__"nvqinshi"
  
]));
	

	setup();
	replace_program(ROOM);
}
