// Room: /d/new_taohua/andao.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ROOM;
int do_push(string);
void create()
{
        set("short", "����");
        set("long", @LONG
���ǻ�ҩʦ�����µ����ܰ���������ש���ɵ�ǽ,ǽ����
һյ�͵ƣ����һ��һ���ģ���ɭɭ�㲻�����˸���ս��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "up" : __DIR__"muxue",
]));
        set("item_desc", ([
                "wall": "ǽ���ƺ���һ����ť��button����\n",
                "ǽ��": "ǽ���ƺ���һ����ť��button����\n"
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
                return notify_fail("push <����>\n");
        if(arg="button" || arg="��ť")
	{
		if(me->query_skill("qimen-bagua",1)>70)
		{
			me->move(__DIR__"huangwshi");
			write("����ǽ�ϵİ�ť��һ������ǰһ�����ѵ��˻�ҩʦ���ҡ�\n");
			return 1;
		}
		else
		{
			me->move(__DIR__"huangwshi");
			write("����ǽ�ϵİ�ť��һ������ǰһ�����ѵ��˻�ҩʦ���ҡ�\n");
			write("��һ��С�ģ������˱��ϵ�����\n");
			huang=new(CLASS_D("taohua")+"/huang");
			huang->move(__DIR__"huangwshi");
			write(RED"��ҩʦ��ȵ����㾹��͵�ҵ��飬��������\n"NOR);
			huang->kill_ob(me);
			return 1;	
		}
	}	
	return 0;
}	
