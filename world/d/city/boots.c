// boots.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "���Ь��");
        set("long", @LONG
�����Ǿ�ʦ������һ��Ь�ꡣ��������������������ǰ�
���ϵꡣ����ͦ��������һ������Ƥ�����ζ�����̨����ļ�
���Ϸ����˸�ʽ��Ƥѥ�����м����������æµ��
    ���ſ���һ���������(sign)��
LONG
        );
        set("exits", ([
                "south"   :  __DIR__"street11" ]) );

        set("objects", ([
              __DIR__"npc/shoer.c" : 1, ]) );

        set("item_desc", ([
                "sign": (: look_sign :),]) );

        setup();

}

string look_sign(object me)
{
        return HIY "ר����ʽЬ��\n"NOR;
}

