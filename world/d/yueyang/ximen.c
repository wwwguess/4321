
// Room: /city/ximen.c
// YZC 1995/12/04

#include <ansi.h>

inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", WHT "����" NOR);
        set("long", @LONG
        ���������ţ�����ǰ�����⵽���˵Ĺ�������Ե���Щ�ưܡ���������
������ǿǿ�����ϳ������š��������֣���ǽ�����ż���ͨ����ʾ(gaoshi)��
�������ﷸ��������ıؾ�֮�أ��ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס�������ʡ�һ��
��ֱ����ʯ���������������졣�����ǽ��⣬����ġ����εġ���·�ģ�����
�Ҵҡ������ǳ��
LONG
        );
        set("outdoors", "city");

        set("exits", ([
        "east" : __DIR__"xidajie1",
        ]));
        set("objects", ([
                __DIR__"npc/bing" : 2,
        ]));
        setup();
}
