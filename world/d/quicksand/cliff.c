
inherit ROOM;

void create()
{
        set("short", "绝崖");
        set("long", @LONG
这座绝崖上光秃秃的，除了一块块的巨石什么也没有。这里的天色似乎
也特别暗淡，暗淡得使人感到人生的灰暗。向下则是一望无底，雾气蒙蒙的
死谷。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"mroad2",
]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/poslave" : 2,
        ]) );
        set("item_desc", ([
                "死谷": "谷壁并不很光滑，你似乎有一线希望可以爬(climb)下去。\n"
        ]) );


        setup();
}
void init()
{
        add_action("climbing", "climb");
}

int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "valley" || arg == "down" || arg == "死谷")
        {
        me = this_player();
        message_vision("$N抓着突出的石角，慢慢的顺着谷壁爬了下去。\n", me);
        me->start_busy(7);
        call_out("fliping",7,me);
        me->stop_busy();
        return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}
int fliping(object me)
{
        me->move(__DIR__"valley");
        message_vision("$N顺着谷壁爬了下来。\n", me);
        return 1;
}

