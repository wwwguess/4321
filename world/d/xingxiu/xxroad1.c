// Room: /d/xingxiu/xxroad1.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
������һ����ʯ����ϡ�������ͨ�����ݶɿ����.
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

