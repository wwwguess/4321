#include <ansi.h>

inherit ROOM;

void create()
{
 set("short", YEL "����" NOR);
        set("long", @LONG
 ���Ƕ���,�����Ͻ��ǵ����һ�����ߡ��ߴ�ĳ���͸¶�����ϡ����ſ�����
�ܶ��������ء������������Ͻ����ˡ�
LONG
        );
        set("outdoors", "city");
        set("exits", ([
        "south" : __DIR__"wumen",
        
        ]));
        set("objects", ([
   __DIR__"hchshw1" : 3,
   __DIR__"hchshw2" : 3,
   __DIR__"hchshw3" : 3,
 

        ]));
        setup();
}
int valid_leave(object me, string dir)
{
	if( dir == "north" ) { 
		if( present("shi wei", environment(me)) 
		
		)
			return notify_fail(RED"������ݺݵ�˵��:�ʹ��صأ����ݶ����ô���������ȥ,����Ƥ��֮��! \n"NOR);
	}
       return :: valid_leave(me, dir);
}          
