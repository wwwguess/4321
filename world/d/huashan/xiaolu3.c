// Room: /d/shaolin/jlyuan.c
// Date: YZC 96/01/19


#include <ansi.h>
#include <login.h>

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
������һ��С·�ϣ�С·һ�������£���һ�������ͱڡ�·������������Զ��У�
����������ͨ����·�ϴ��δ����������һ������һЩС�ɴ��ͱ��������
LONG
        );
        
        set("exits", ([
                "eastdown" : __DIR__"xiaolu2",
                "southdown" : __DIR__"xiaolu4",
        ]));

        setup();
        set("no_clean_up", 0);
        setup();


}
