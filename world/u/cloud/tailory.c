// tailory.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "��ׯ");
	set("long", @LONG
��������վ�ڲ�ׯ��
    �����ſڵ�ǽ���Ϲ���(sign)��
LONG
        );
        set("exits", ([
                "north"          : "/u/cloud/nwroad2" ]) );

        set("objects", ([
                "/u/cloud/npc/tailor" : 1,
 ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д�����¡�\n";
}

