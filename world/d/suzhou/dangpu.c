// Room: /d/suzhou/dangpu.c
// by dwolf
//97.11.4 

#include <ansi.h>
inherit HOCKSHOP;

void create()
{
	set("short", MAG"����"NOR);
	set("long", @LONG
	����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ����̨
�ϰ���һ������(paizi)����̨�������ϰ尢�⣬һ˫Ư���Ĵ��۾��������´�����
�㡣һ����ĺ������ɫ�Ķ�����������
LONG
	);
	set("no_beg",1);
	set("no_steal", 1);

	set("item_desc", ([
		"paizi" : @TEXT
		��ƽ����    
	Ŀǰ�����ṩ���·���
    pawn(�䵱/�鿴�ѵ䵱��Ʒ)
    redeem(��ص䵱��Ʒ)
    value(����Ʒ����)��
TEXT
	]));
	set("objects", ([
                __DIR__"npc/axiu" : 1, 
		__DIR__"npc/eba" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"eroad1",
	]));

        set("dangpu_location","suzhou");
	setup();
}

