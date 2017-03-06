
// Room: /d/new_taohua/midao.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;

void create()
{
        set("short", "墓中秘室");
        set("long", @LONG
这是黄药师之妻的墓中的秘室，正面是是一张供桌，桌上摆放着她的灵牌。
两侧是一些殉葬的宝物。最引人注目的是一本书，上写“九阴真经”四字。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "out" : __DIR__"muxue",
        ]));
        set("item_desc", ([
                "book": "这本书上的字是用针刺在人皮上的，你可将它拾起（pick）。\
n",
                "九阴真经": "这本书上的字是用针刺在人皮上的，你可将它拾起（pick�
n"
        ]) );

        setup();
}
 void init()
{
        add_action("do_love","pick");
}
int do_love(string arg)
{
        object me,book;
        me=this_player();
        if(!arg )
                return notify_fail("pick <东西>\n");
        if(query_temp("mark/been_get")) return notify_fail("书已被拿走了。\n");
        if((arg == "book"||arg == "九阴真经") && me->query_skill("qimen-bagua",1
)>60) {
                        message_vision( "\n$N将书拿了起来。\n",this_player());
                        book=new(__DIR__"obj/ninebook");
                        book->move(me); 
			me->set("marks/ninebook",1);
                        set_temp("mark/been_get",1);
                        return 1;
                }
        message_vision( "\n秘室中的机关突然发动,将$N挤成了一滩肉泥。\n",this_player());
        me->die();
        return 1;
}
void reset()
{
    ::reset();
        delete_temp("mark/been_get");
    if(query("exits/enter"))
        delete("exits/enter");
}
