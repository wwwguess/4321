// weapony.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "������");
        set("long", @LONG
��������վ�ڱ�������
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "west"          : "/u/cloud/nroad1" ]) );

        set("objects", ([
                "/u/cloud/npc/weaponor" : 1,
 ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д����ר����ʽ����\n";
}

