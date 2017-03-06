// southdoor.c
#include <room.h>

inherit ROOM;

string look_notice();

void create()
{
        set("short", "��ʦ��һ��");
        set("long", @LONG
��������ʦ����һ�š���ǽ�����ż��ŹټҲ���(notice)����
�����Ǵ�����£���ʱ�������������������ǳ���ľ�ʦ����վ
̧ͷ�ɼ�Զ�������Ⱥɽ�����߾��Ǿ�ʦ�Ľֵ��ˡ�
LONG
        );

        set("item_desc", ([
                "notice": (: look_notice :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
              "out"          : __DIR__"wyizhan",
                "east"          : __DIR__"street14" ]) );

        set("objects", ([
                __DIR__"npc/guard1" : 3 ,]) );  

        create_door("out", "����", "enter" );
        setup();
}

string look_notice()
{
    return "������д�������������˳�û��������С�ġ�\n";
}
/*
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
            me->set("have_token",);
                return 1;
                }

        return ::valid_leave(me,dir);
}
*/
