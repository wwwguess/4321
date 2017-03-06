// eastdoor2.c
#include <room.h>

inherit ROOM;

string look_notice();

void create()
{
        set("short", "��ʦ������");
        set("long", @LONG
�����Ǿ�ʦ�Ķ����š������ϲ��ż������ģ���־�˱��ŵ���
�ǽ��졣��¥�����ż������������ˣ���ǽ����һ�Ÿո�ճ����
ȥ�Ĳ���(notice)��һȺ����Χ�Źۿ��������ǳ��⣬�����Ǿ�ʦ
�Ľֵ���
LONG
        );

        set("item_desc", ([
                "notice": (: look_notice :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
//                "out"          : __DIR__"e2soad1",
                "west"          : __DIR__"street10" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3 ,]) );  

        create_door("out", "����", "enter" );
        setup();
}

string look_notice()
{
     return "������д��������Ҫ��----������䡣\n";
}

int valid_leave(object me,string dir)
{
        if ( dir=="out" &&
                ( !(string) me->query("marks/��ʦ")
                || !(string) me->query("marks/����") ) ) {
                tell_object (me, "��ʦ�سǱ�˵����û�йٸ�ͨ��κ��˲��ܳ��뾩ʦ��\n");
                return notify_fail("���Ƿ����·����ʦ�سǱ���ס�ˡ�\n");
                }

        if (me->query("marks/����")) {
                ::valid_leave(me,dir);
                me->set("marks/����", 0);
                return 1;
                }

        return ::valid_leave(me,dir);
}

