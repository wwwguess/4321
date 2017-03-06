
inherit ROOM;

void create()
{
        set("short", "穹形石窟");
        set("long", @LONG
这是在大招寺右壁上的石窟。窟里有一幅色彩鲜艳但却恐怖之极的壁画。
画上是一个狰狞娇异的罗刹鬼女，正在吮吸一个凡人的脑髓。精密细致的画面
看来栩栩如生。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"woodhouse",
  "south" : __DIR__"templeyard",
]));
        setup();
        replace_program(ROOM);

}

