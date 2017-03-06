// Room: /d/hhu/hhupath3.c

inherit ROOM;

void create()
{
	set("short", "林荫道");
	set("long", @LONG
你现在走在河海大学校内的林荫道上
    路南是河海大学网络管理中心（Center）。
    四周风景很美。
LONG
	);
	set("item_desc", ([ ]));
        set("objects",([
           __DIR__"npc/student_1":3,
           __DIR__"npc/student_2":2,
           __DIR__"npc/yanjiusheng":1,
        ]));
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"hhupath2",
  "northwest" : __DIR__"hhupath4",
  "southup" : __DIR__"roadtocenter",
]));
	set("no_clean_up", 0);

	setup();
}
