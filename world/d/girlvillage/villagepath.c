#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ʯ����");
        set("long", @LONG
��ʯ����һ�ְԵ���ָ����ʯ���ֵĿ̵���
��������ߣ�ɱ��뷣����� 
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"villagepath0",
  "west"  : __DIR__"wvillage0",
]));
        set("outdoors", "girlvillage");
        
        setup();
        replace_program(ROOM);
        
}
                          