// Room: /d/new_taohua/nanyushi.c

inherit ROOM;

void create()
{
	set("short", "ÄÐÔ¡ÊÒ");
	set("long", @LONG
         ÄÐÔ¡ÊÒ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "out" : __DIR__"yushimen",
  "east": __DIR__"nanqinshi"
  
]));
	

	setup();
	replace_program(ROOM);
}
