#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "巨石脚下");
        set("long", @LONG
巨石上用一种霸道的指法入石三分的刻道：
男人入村者，杀无敕！！！ 
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"villagepath0",
  "west"  : __DIR__"wvillage0",
]));
        set("outdoors", "girlvillage");
        
        setup();
        replace_program(ROOM);
        
}
                          