// zaihuoy.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "�ӻ���");
	set("long", @LONG
��������վ���ӻ�����
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
		"north"		: "/u/cloud/nwroad3",
                "east"          : "/u/cloud/nroad2" ]) );

	set("objects", ([
                "/u/cloud/npc/seller" : 1,
 ]) );

        set("item_desc", ([
                "sign": (: look_sign :)
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д�����̡�\n";
}

