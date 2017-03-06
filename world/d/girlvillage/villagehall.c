inherit ROOM;

void create()
{
        set("short", "九阴派大厅");
        set("long", @LONG
九阴派起始于六百年前。到今天弟子已遍布天下。九阴派
现任掌门人已修炼到反老还童的境界。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
      "north" : __DIR__"villagepath",
      "west"  : __DIR__"wvillage15",
      "east"  : __DIR__"gpalace",
]));
        set("outdoors", "girlvillage");
        set("valid_startroom", 1);
        set("objects", ([
                 __DIR__"npc/master" : 1 ]) );
                 
        setup();
        
}
                               