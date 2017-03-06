// Room: /d/new_taohua/muxue.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;

void create()
{
        set("short", "��ҩʦ��Ĺ��");
        set("long", @LONG
�����ǰ������һƬ��ɫ���ԣ����ص���������һ���׻������С����
�׻�֮����һ�鶫���߸�¡���߽�һ��ԭ����һ��ʯ�ء���ǰĹ���Ͽ���
���һ���Ů����������֮ڣ������Χ�������£��ƺ��̲������ܡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "out" : __DIR__"wifemu",
    "down" :__DIR__"andao",
]));
        set("item_desc", ([
                "mubei": "����д��'������֮����,�������ʧ�ȣ���Ǹ߶��޽ף�'\n",
                "Ĺ��": "����д��'������֮����,�������ʧ�ȣ���Ǹ߶��޽ף�'\n"
]));

        setup();
}
 void init()
{
	add_action("do_love","write");
}  
int do_love(string arg)
{
	object me;
	me=this_player();
        if(!arg )
                return notify_fail("write <��>\n");
        if(query("exits/enter")) return 0;
        if(arg[0..11] == "���˺���˭��" && random(10)>8 && me->query_skill("qimen-bagua",1)>50) {
                        message_vision( "\n$N˳��Ĺ���ϵ��ּ�����һ�飬Ĺ��ͻȻ����ϻ���������¶��һ���ص���\n",this_player());
	                set("exits/enter",__DIR__"midao");
                        return 1;
                }
        return notify_fail("\n��˳��Ĺ���ϵ��ּ�����һ�顣\n");
}  
void reset()
{
    ::reset();
    if(query("exits/enter"))
    	delete("exits/enter");
}
