// Room: /d/taohua/wifemu.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ҩʦ��Ĺ��");
        set("long", @LONG
���ǻ�ҩʦ��Ĺ®֮�⡣��ҩʦ�������ͷ׷˼�������ޣ�
�·�û��ע�⵽�㡣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"yonglu5",
    "enter" :__DIR__"muxue",
]));    
        set("objects",([
       		CLASS_D("taohua")+"/huang" : 1,
       	]) );

        set("outdoors", "taohua");

        setup();
} 
int valid_leave(object me, string dir)
{      
	object ob,*inv;
        int i,ss;
	me = this_player();
	inv = all_inventory(me);
	i=0;
	while(i<sizeof(inv))
                {
                        if(base_name(inv[i]) == __DIR__"obj/ninebook") {ss = 1;}
                        i++;
                }
	if(ob=present("huang", this_object()) && ss)
                {
                	message_vision(BLU "��ҩʦ����˵�����������������������뿪����ġ���\n" NOR,me);
		        return 0;
                } 
    return 1;
}
