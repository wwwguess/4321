inherit ROOM;

void create()
{
        set("short", "女人村");
        set("long", @LONG
你盲目地走在漫无边际的女人村里。环顾四周，四周的景色
和你刚走过的地方不无一样。三三俩俩的女人从你身边快速穿过，
向你投来异样的眼光。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"wvillage5",
          "south" : __DIR__"wvillage7",
            "west"  : __DIR__"wvillage2",
              "east"  : __DIR__"wvillage10",
]));

        set("outdoors", "girlvillage");
        set("objects", ([
                __DIR__"npc/thousand_hand" : 1,
        ]) );
        
        setup();
        replace_program(ROOM);
        
}
                
                      