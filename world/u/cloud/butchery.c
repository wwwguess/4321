// butchery.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "������");
	set("long", @LONG
��������վ�������������Ϲ�����Ѫ���ܵ����⣬һ����
�������������ʱ�м�ֻ��Ӭ�����������ȥ��
    �����ſڵĵط���һ��ţ�ǵ�ɵ�����(sign)������д��Щ
ʲô��
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("exits", ([
                "east"          : "/u/cloud/nwroad1" ]) );

        set("objects", ([
                "/u/cloud/npc/butcher" : 1,
		"/u/cloud/npc/fly.c" : 6,
 ]) );

        setup();

}

string look_sign(object me)
{
        return (@LONG
���꼴���չ�������
LONG);
}

