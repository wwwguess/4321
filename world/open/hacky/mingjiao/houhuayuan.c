 // houhuayuan1.c
// by yuer
inherit ROOM;
void create()
{
        set("short", "后花园");
        set("long", @LONG
这里是光明顶的后花园，种满了花草。几个小童正在浇花
北边有一个幽雅的小院。
LONG
        );
        set("exits", ([
		"north" : __DIR__"yueliangmen",
		"south" : __DIR__"zoulang0",
		 "west" : __DIR__"chitang",
		 "east" : __DIR__"jiashan",
	]));
        
        set("no_clean_up", 0);
        set("outdoors", "mingjiao" );
        setup();
       
}


