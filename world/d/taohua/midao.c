
// Room: /d/new_taohua/midao.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;

void create()
{
        set("short", "Ĺ������");
        set("long", @LONG
���ǻ�ҩʦ֮�޵�Ĺ�е����ң���������һ�Ź��������ϰڷ����������ơ�
������һЩѳ��ı��������עĿ����һ���飬��д�������澭�����֡�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "out" : __DIR__"muxue",
        ]));
        set("item_desc", ([
                "book": "�Ȿ���ϵ��������������Ƥ�ϵģ���ɽ���ʰ��pick����\
n",
                "�����澭": "�Ȿ���ϵ��������������Ƥ�ϵģ���ɽ���ʰ��pick�
���\n"
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
                return notify_fail("pick <����>\n");
        if(query_temp("mark/been_get")) return notify_fail("���ѱ������ˡ�\n");
        if((arg == "book"||arg == "�����澭") && me->query_skill("qimen-bagua",1
)>60) {
                        message_vision( "\n$N��������������\n",this_player());
                        book=new(__DIR__"obj/ninebook");
                        book->move(me); 
			me->set("marks/ninebook",1);
                        set_temp("mark/been_get",1);
                        return 1;
                }
        message_vision( "\n�����еĻ���ͻȻ����,��$N������һ̲���ࡣ\n",this_player());
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
