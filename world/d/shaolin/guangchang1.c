// Room: /d/shaolin/smdian.c
// Date: YZC 96/01/19
#include <ansi.h>

inherit ROOM;


void init();
void close_gate();
int do_open(string);
int do_close(string);
string look_gate();


void create()
{
    set("short", "广场");
        set("long", "这里是少林寺前的广场，整个广场由大块的青石铺成，极为平坦。
但因年代久远，都有些破损。丛丛小草从石板的缝隙中长了出来。广场
周围都是密密的松树林，四角上各放了几块石碑，字迹都甚为模糊。正
前方黄墙碧瓦，飞檐翘檩，正中一道二丈来宽，三丈来高的朱红杉木包
边大门(gate)。上方一块大匾，龙飞凤舞地书着"+"\n\n"+

"                          "+YEL "少    林    寺" NOR +

"\n\n"+"寺前三三两两的站着几个僧人。"  
);     
    set("exits", ([
        "east" : __DIR__"guangchang1e",
        "south" : __DIR__"shijie11",
        "west" : __DIR__"guangchang1w",
    ]));

    set("outdoors", "shaolin");
    set("item_desc",([
        "gate"        :    (: look_gate :),
    ]));
    set("objects",([
        CLASS_D("shaolin") + "/qing-fa" : 1,
    ]));
    setup();
        // To "load" the board, don't ever "clone" a bulletin board.
        call_other( "/obj/board/shaolin_b", "???" );     
}
void init()
{
    add_action("do_open", "open");
}   
void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"smdian")) )
		room = load_object(__DIR__"smdian");
	if(objectp(room))
	{
		delete("exits/north");
			message("vision", "僧兵上前把大门关了起来。\n", this_object());
		room->delete("exits/south");
		message("vision", "乒地一声，里面有人把大门关上了。\n", room);
	}
}

int do_close(string arg)
{
	if (!query("exits/south"))
		return notify_fail("大门已经是关着的了。\n");

	if (!arg || (arg != "gate" && arg != "north"))
		return notify_fail("你要关什么？\n");

//	message_vision("$N朝僧兵点了点头。\n", this_player());

	remove_call_out("close_gate");
	call_out("close_gate", 2);

	return 1;
}

int do_open(string arg)
{
	object room;

	if (query("exits/north"))
		return notify_fail("大门已经是开着了。\n");

	if (!arg || (arg != "gate" && arg != "north"))
		return notify_fail("你要开什么？\n");

	if(!( room = find_object(__DIR__"smdian")) )
		room = load_object(__DIR__"smdian");
	if(objectp(room))
	{
		set("exits/north", __DIR__"smdian");
		message_vision("$N使劲把大门打了开来。\n", this_player());
		room->set("exits/south", __FILE__);
		message("vision", "吱地一声，里面有人把大门打开了。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}

string look_gate()
{
	return "一道三丈来高的朱红杉木包铜大门。\n你可以尝试打开(open)它。\n";
}

/*
int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "south" ) return 0;

	return ::valid_leave(me, dir);
}
*/
