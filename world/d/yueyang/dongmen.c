
// Room: /city/dongmen.c
// YZC 1995/12/04

#include <ansi.h>

inherit ROOM;


void create()
{
        set("short", GRN "����" NOR);
        set("long", @LONG
        �������������ţ��������Ϸ����š����š�����������֣���ǽ�����ż���
�ٸ���ʾ(gaoshi)���ٱ��Ǿ����ע���Ź������ˣ������С��Ϊ�һ����ֱ
����ʯ���������������졣�����ǽ��⣬��Լ�ɼ�һƬһ���޼ʵ����֣���
��Ī�⡣�����ǳ��������һƬïʢ�������֡�
LONG
        );
        set("outdoors", "city");

        set("item_desc", ([
                "gaoshi" : "�Ͻ��ؽ����֣�\n",
        ]));
        set("exits", ([
                "north" : __DIR__"ml1",
                "west" : __DIR__"dongdajie1",
                "northeast" : "/d/road/rwctoyy1",
        ]));

        set("objects", ([
                __DIR__"npc/bing" : 2,
        ]));

        setup();
}

