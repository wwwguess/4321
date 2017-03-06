// Room: /d/hhu/hhusport.c

inherit ROOM;

void create()
{
	set("short", "河海体育场");
	set("long", @LONG
现在你来到河海大学的体育场，
    体育场上一片生龙活虎的景象，
    由此向东南可以到河海大学的交通中心。
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"studentroom3",
  "southeast" : __DIR__"hhu3road1",
]));
	set("no_clean_up", 0);

	setup();
}
