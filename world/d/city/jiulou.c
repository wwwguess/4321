// jiulou.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "̫�׾�¥");
        set("long", @LONG
���ߵ���һ�Ҵ��¥����ܵ�װ�ν�ڻԻͣ������ۻ����ң�����
�ߵ�����Ҳ�������������Ǿ��ǵĵ�һ���¥����¥�Ĳ�����Զ��������
�����⾭�����Կ���һЩ��ٹ��壬�����������Ҳ��΢��������һ����
����
LONG
        );

        set("exits", ([
                "east":		__DIR__"street5",
		"up":		__DIR__"jiulou_2",
		]) );

        set("objects", ([
                __DIR__"npc/waiter" : 	1,
		__DIR__"npc/boss":	1,
		]) );
        setup();
}


