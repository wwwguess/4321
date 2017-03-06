// marry_room.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "����ׯ");
        set("long", @LONG
��������վ�ں���ׯ�������ר�����˵޽��Լ�ͽ����Լ�ĵط���
�������еķ򸾶���������ϲ����Ե�ģ�������������Ҳ�����Ľ��������
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "south"          : "/u/cloud/wroad1", 
         ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("objects", ([
                "/u/cloud/npc/mei_po" : 1,
        ]) );
 
        setup();

}

string look_sign(object me)
{
        return "�޽������Լ��\n";
}

