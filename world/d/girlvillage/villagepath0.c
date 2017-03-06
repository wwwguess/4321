inherit ROOM;

void create()
{
        set("short", "山坳路");
        set("long", @LONG
这是山谷中的一条小径。往南就是雪亭镇，往西则是一个小小
的村落。村落的入口立了一块大石，石上刻着几个大字。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"villagepath",
    "south"  : "/d/green/road5",
]));
        set("outdoors", "girlvillage");
        
        setup();
        replace_program(ROOM);

}
                            