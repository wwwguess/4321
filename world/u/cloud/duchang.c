// duchang.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "�ĳ�");
	set("long", @LONG
��������վ�ڶĳ���
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "north"          : "/u/cloud/eroad1", 
	 ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

	set("objects", ([
		"/u/cloud/npc/judge" : 1,
        ]) );
 
        setup();

}

string look_sign(object me)
{
        return "�ģ�ʤ��Ӯ˫��\n";
}

