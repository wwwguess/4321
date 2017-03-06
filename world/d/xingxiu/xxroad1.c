// Room: /d/xingxiu/xxroad1.c

inherit ROOM;

void create()
{
        set("short", "大道");
        set("long", @LONG
你走在一条青石大道上。东南面通向兰州渡口驿道.
LONG
        );
        set("exits", ([
  "northup" : "/d/xingxiu/xxroad3",
  "southeast" : "/d/road/rdktojyg4",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

