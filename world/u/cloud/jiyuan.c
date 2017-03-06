// jiyuan.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "����Ժ");
        set("long", @LONG
��������վ������Ժ��
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "south"  : "/u/cloud/eroad1", 
                "up"  : "/u/cloud/jiyuan2",
        ]) );

        set("objects", ([
                "/u/cloud/npc/mother" : 1,
        ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д��������Ժ\n";
}

