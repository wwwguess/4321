// Room: /d/xingxiu/xxroad2.c

inherit ROOM;

void create()
{
        set("short", "黄土大道");
        set("long", @LONG
这是一条黄土大道。东面隐约可以看到有座小山。
LONG
        );
        set("exits", ([
  "southeast" : "/d/road/rdktojyg4",
           "west" : "/d/xingxiu/jiayuguan",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

