inherit ROOM;
void create()
{
        set("short", "后花园");
        set("long", @LONG
这里是华山派的后花园，种满了花草。园中有个水井
可以用来装水。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"buwei2",
   "west" : __DIR__"shufang",
  "south" : __DIR__"sleeproom",
  "east":__DIR__"houhuayuan1",
  ]));

        set("objects", ([
                CLASS_D("huashan") + "/liangfa" : 1,
		__DIR__"obj/zitanhua.c" :1,	
	]));

        set("resource/water",1);
        set("no_clean_up", 0);
        set("outdoors", "xx" );
        setup();
       
}
