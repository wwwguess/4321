// biaoju.c

//#include <room.h>
#include <ansi.h>
inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", HIR "��Զ�ھ�" NOR);
        set("long", @LONG
��������վ���ھ���
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "north"          : "/u/cloud/eroad2" ]) );

        set("objects", ([
                CLASS_D("guardman") + "/b_header" : 1,
		CLASS_D("guardman") + "/biaotou1" : 1,	
                "/u/cloud/npc/bfighter" : 2,
        ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
	set("valid_startroom", 1);
        setup();

}

string look_sign(object me)
{
        return "����д����"+ HIY "�ڡ�\n" NOR;
}

