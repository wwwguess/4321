
// Room: /city/dongmen.c
// YZC 1995/12/04

#include <ansi.h>

inherit ROOM;


void create()
{
        set("short", GRN "东门" NOR);
        set("long", @LONG
        这是岳阳东城门，城门正上方刻着“东门”两个楷书大字，城墙上贴着几张
官府告示(gaoshi)。官兵们警惕地注视着过往行人，你最好小心为妙。一条笔直
的青石板大道向东西两边延伸。东边是郊外，隐约可见一片一望无际的树林，神
秘莫测。西边是城里。北面有一片茂盛的青竹林。
LONG
        );
        set("outdoors", "city");

        set("item_desc", ([
                "gaoshi" : "严禁沿街乞讨！\n",
        ]));
        set("exits", ([
                "north" : __DIR__"ml1",
                "west" : __DIR__"dongdajie1",
                "northeast" : "/d/road/rwctoyy1",
        ]));

        set("objects", ([
                __DIR__"npc/bing" : 2,
        ]));

        setup();
}

