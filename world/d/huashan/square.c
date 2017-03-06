// Room: /d/huashan/square.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
�����ǻ�ɽ�ɵ����䳡��ͨ������໪ɽ�ɵ����ڴ�ϰ������������
����ӭ���ˡ��ϱߵķ������Ϲ���һ���ң����顸������Ϊ��������
����(northwest)�ƺ�����С·(road)ͨ��ɽ�ϡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"buwei1",
            "north" : __DIR__"yunu",
        ]));
        set("objects", ([
                CLASS_D("huashan") + "/lao" : 1,
                __DIR__"npc/dizi" : 5 ]));

        set("item_desc", ([
                "road": "����һ��ͨ��ɽ���С·���ƺ�û�о�ͷ��\n"
        ]) );
        set("no_clean_up", 0);

        setup();
}
void init()
{
      //  add_action("do_northwest", "nw");
        add_action("do_northwest", "northwest");
}
int do_northwest()
{
        object me;
        me = this_player();
        if( me->query_temp("marks/˼1") ) {
                message("vision",
me->name() + "��������С·��ȥ��\n",
                environment(me), ({me}) );
                me->move("/d/huashan/xiaolu1");
                message("vision",
me->name() + "����������С·��\n",
                environment(me), ({me}) );
                return 1;
                }
        else {
                write("����С·�ƺ�û�о�ͷ��\n");
                return 1;
                }
       
}
