// Room: /u/sunhill/hillsmoke/entrance.c

inherit ROOM;

void create()
{
        set("short", "ɽ������");
        set("long", @LONG
������ɽ�����⡣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yard",
  "northdown" : "/u/cloud/sunhill/road4",
]));
        set("outdoors", "sunhill");

        setup();
        replace_program(ROOM);
}

