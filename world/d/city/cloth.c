// cloth.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "��ϲ���ׯ");
        set("long", @LONG
��ϲ���ׯ�Ǿ�ʦ�е�һ�Ҹոտ�ҵ��רӪ��ñ���̵ꡣ����
�˿�ϡ�٣��Եõ��̿յ����ġ���̨�����ҵ�̯�ż�ƥ��С����
ׯ���ϰ��ȥ�����ˣ�ֻ���ϰ�����ص��̡���˵��ҵ��̺�����
����һ��ĵ�ƦҲ���ٵ��������¡�
    �����Ϲ���һ��ո�µ�����(sign)��
LONG
        );
        set("exits", ([
                "east"   :  __DIR__"street6" ]) );

        set("objects", ([
              __DIR__"npc/clother.c" : 1, ]) );

        set("item_desc", ([
                "sign": (: look_sign :),]) );

        setup();

}

string look_sign(object me)
{
        return RED"�����������֣�������\n"NOR;
}

