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
                "east" : __DIR__"xiaolu1",
                "westup" : __DIR__"xiaolu3",
        ]));

        setup();
        set("no_clean_up", 0);
        setup();


}
