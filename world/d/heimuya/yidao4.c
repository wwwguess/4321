// Room: /d/heimuya/.c
// write by: dfbb 
// date 97/01/25

#include <localtime.h>
inherit ROOM;
int flag=0;

void create()
{
	set("short","驿道");
	set("long", @LONG
    这是通向 "保定城"的驿道。四周人来人往。挑担子的
行商，赶着大车的马夫，上京赶考的书生，熙熙攘攘，非常热闹。
路边全是杂草.

LONG
	);

	set("exits", ([
		"south" :__DIR__"yidao3",
		"north" :__DIR__"yidao5",

	]));

        set("objects",([
                __DIR__"npc/jiao_zhong1" : 2,
        ]));

	set("outdoors", "heimuya");
	setup();
}

void init()
{
        add_action("do_search", "search");
}


int do_search(string arg)
{
        mixed t;
        object ob;

        if( arg != "杂草" ) return 0;

        t = NATURE_D->game_time(1);
        // Can only be found during 11:00 to 14:00
        if( flag || (t[LT_HOUR] < 10) || (t[LT_HOUR] >13) ) {
                message_vision("$N在杂草丛里找来找去，但是什么也没有找到。\n", this_player());
                return 1;
        }
        flag = 1;
        ob = new(__DIR__"obj/gou");
        ob->move(this_player());
        message_vision("$N在草丛里找来找去，结果发现了一支吴钩！\n", this_player());
        return 1;
}

void reset()
{
        flag = 0;
        ::reset();
}

