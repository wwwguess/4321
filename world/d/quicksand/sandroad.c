inherit ROOM;

void create()
{
        set("short", "沙砾小径");
        set("long", @LONG
这里的地上是一种黄褐色，红褐色的石砾镶嵌在细细的黄沙之中，
给人以极其怪异的感觉。这里就是西域与中原的中间地带，再往西就是
边塞。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"huangyie4",
  "west" : __DIR__"saikou",
]));
        set("outdoors", "quicksand");

        setup();
        replace_program(ROOM);
}
