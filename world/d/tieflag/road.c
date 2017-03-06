// road.c
inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
这里靠近佛教名山千佛洞，又是往来山上山下的必经之路。
在路边有一片小小树林，一张石桌，几张石凳。一个小贩
在大声叫卖，生意颇为兴隆。
LONG
        );
        set("exits", ([
  "eastup" : __DIR__"road0",
  "north" : __DIR__"troad4",
]));
        set("objects", ([
               __DIR__"npc/xiaofan" : 1,
       ]) );
        set("outdoors", "tieflag");
        setup();
}
