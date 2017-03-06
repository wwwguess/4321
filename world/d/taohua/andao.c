// Room: /d/new_taohua/andao.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ROOM;
int do_push(string);
void create()
{
        set("short", "暗道");
        set("long", @LONG
这是黄药师卧室下的秘密暗道。用青砖砌成的墙,墙上有
一盏油灯，火光一闪一闪的，阴森森你不禁打了个寒战。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "up" : __DIR__"muxue",
]));
        set("item_desc", ([
                "wall": "墙上似乎有一个暗钮（button）。\n",
                "墙壁": "墙上似乎有一个暗钮（button）。\n"
        ]) );


        setup();
}
void init()
{
        add_action("do_push","push");
}
int do_push(string arg)
{
        object me,huang;
        me=this_player();
        if(!arg )
                return notify_fail("push <东西>\n");
        if(arg="button" || arg="按钮")
	{
		if(me->query_skill("qimen-bagua",1)>70)
		{
			me->move(__DIR__"huangwshi");
			write("你在墙上的按钮上一按，眼前一花，已到了黄药师卧室。\n");
			return 1;
		}
		else
		{
			me->move(__DIR__"huangwshi");
			write("你在墙上的按钮上一按，眼前一花，已到了黄药师卧室。\n");
			write("你一不小心，触动了边上的响玲\n");
			huang=new(CLASS_D("taohua")+"/huang");
			huang->move(__DIR__"huangwshi");
			write(RED"黄药师大喝道：你竟敢偷我的书，拿命来！\n"NOR);
			huang->kill_ob(me);
			return 1;	
		}
	}	
	return 0;
}	
