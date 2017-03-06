// eastdoor1.c
#include <room.h>

inherit ROOM;

string look_notice();

void create()
{
        set("short", "��ʦ��һ��");
        set("long", @LONG
��������ʦ�Ķ�һ�š����ſ�ʮ�����ֳֵ�ǹ��ʿ�����ڼ��
���������ˡ�������һЩ�����ûʵĴ󳵻���ʻ����������Ǿ�ʦ
�Ĺٻ��˼ҳ��ι�������ǽ����һ�ų¾ɵĲ���(notice)��������
���⣬�羰�续�������Ǿ�ʦ�Ľֵ���
LONG
        );

        set("item_desc", ([
                "notice": (: look_notice :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
                //"out"          : __DIR__"e1soad1",
                "west"          : __DIR__"street9" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3, ]) );  

        //create_door("out", "����", "enter");
        setup();
}

string look_notice()
{
     return "���澭�紵��ɹ���ּ��Ѿ����ɷֱ��ˡ�\n";
}

int valid_leave(object me,string dir)
{
        if ( dir=="out" &&
                ( !(string) me->query("marks/��ʦ")
                && !(string) me->query("marks/����") ) ) {
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
