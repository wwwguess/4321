//Room:/d/heimuya/midao/midao13.c 
//write by dfbb@hero
//Date: 1/25/96
inherit ROOM;

void create()
 {
        set("short", "地下密道");
        set("long", @LONG 这里黑漆漆的,只有墙壁上点着一盏昏暗的油灯
 潮湿的气味令你十分不舒服,只想快点走出这个鬼地方.
LONG );
        set("exits", ([
          "north" : __DIR__"midao5",
           "east" : __DIR__"midao14",
           "south" : __DIR__"midao24",
           "west" : __DIR__"midao12",
         ]));
        setup();
        replace_program(ROOM); 
}
// the end of the file 

