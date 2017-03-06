// Room: /d/hhu/uproad1.c

inherit ROOM;

void create()
{
	set("short", "上坡路");
	set("long", @LONG
你现在走在河海大学校内的林荫道上
    四周风景很美。
LONG
	);
        set("objects",([
            __DIR__"npc/good_student":1,
        ]));
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"uproad",
  "northup" : __DIR__"hhuhill",
]));
	set("no_clean_up", 0);

	setup();
}
