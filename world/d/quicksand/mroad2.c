inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是一条被人走出来的小山路，虽然不宽却是够一辆马车通行。小路
顺着山中较为平坦地带缓缓向西伸展。向南是一座高耸的绝崖。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"mroad",
  "west" : "/u/guanwai/grassland0",
  "south" : __DIR__"cliff",
]));
        set("outdoors", "quicksand");

        setup();
        replace_program(ROOM);
}
