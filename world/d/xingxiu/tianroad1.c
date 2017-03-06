// room: /d/xingxiu/tianroad1.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这里是一条山路，山风从山上吹来，你冷得瑟瑟发抖。路边是一片
草原。草原上一位牧羊人赶着一群羊。这里向东可以下山。北边传来阵
阵猛兽的啸声。
LONG
        );
        set("exits", ([
            "eastdown" : "/d/road/xingsuhai",
            "north" : __DIR__"tianroad2",
            "westup" : __DIR__"tianroad3",
]));
        set("objects", ([
                __DIR__"npc/herdsman" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

