// Room: /d/xingxiu/xxroad1.c

inherit ROOM;

void create()
{
        set("short", "山脚");
        set("long", @LONG
这里就是六盘山南麓了，山脚是一片茂密的黑松林，经常
有强人出没。
LONG
        );
        set("exits", ([
  "northup" : __DIR__"xxroad3",
  "east" : __DIR__"rcatolz1",
]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

