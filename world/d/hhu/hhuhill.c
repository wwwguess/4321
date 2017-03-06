// Room: /d/hhu/hhuhill.c

inherit ROOM;

void create()
{
	set("short", "山顶平地");
	set("long", @LONG
这是河海大学校内一座小山的山顶，
    正中有一大片草坪（lawn），环境非常优美。
    北面是河海的最高建筑科学馆，东面是教学楼。
    风中传来朗朗的读书声（reading）。
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"uproad1",
]));
        set("objects",([
            __DIR__"npc/obj/beer" : 1,
        ]));
	set("no_clean_up", 0);

	setup();
}
