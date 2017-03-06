
inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这是一条用石板铺成的山道，两旁是茂密的树木。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"road3",
  "southdown" : __DIR__"road1",
]));
	set("outdoors", "taoguan");
        set("objects",(["/obj/npc/pig.c":4]));
	setup();
	replace_program(ROOM);
}
