// Room: /d/hhu/hhupath1.c

inherit ROOM;

void create()
{
	set("short", "林荫道");
	set("long", @LONG
你现在走在河海大学校内的林荫道上
    四周风景很美。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hhupath2.c",
  "east" : __DIR__"hhugate",
]));
	set("no_clean_up", 0);

	setup();
}
