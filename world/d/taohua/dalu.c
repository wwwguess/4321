#include <ansi.h>
inherit ROOM;

void create()
{
         set("short", BLK "ţ�Ҵ�ֵ�" NOR);
        set("long", @LONG
������һ������Ľֵ��ϣ�������һ�����ƾɵ�é�ݷ���
������û�˾�ס�ˡ�����֮��ԭ���ļҼһ�������
����˶�ǽ���ߵ��ư�֮�ء�
LONG
        );
        set("outdoors", "city");

        set("exits", ([
              
    "south" :"/d/quanzhou/jiaxing",
       "north" : __DIR__"xiaowu",
        ]));

        setup();
        replace_program(ROOM);
}
