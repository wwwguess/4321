// Room: /d/new_taohua/huangwshi.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;

void create()
{
        set("short", "��ҩʦ����");
        set("long", @LONG
���ǻ�ҩʦ�����ң���ѩ�׵�ǽ�ڣ��������һ��
��ò�ٸ��Ļ������ǻ��ص�ĸ�׵�����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */

  "south" :__DIR__"shufang",

]));


        setup();
}

void reset()
{
        object *inv;
        int i,no_reset;
        inv=all_inventory(this_object());
        for (i=0;i<sizeof(inv);i++)
        {
            if(base_name(inv[i])==CLASS_D("new_taohua")+"/huang")
                {
                        if (!inv[i]->is_fighting())
                        destruct(inv[i]);
                    else
                        no_reset=1;
                }
        }
        if(!no_reset) ::reset();
}
