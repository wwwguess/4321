#include <ansi.h>

inherit ROOM;

void create()
{
 set("short", YEL "����" NOR);
        set("long", @LONG
 ��������,��˵�ʵ۴����󳼶��������￳ͷ�����������������ȷ��һ��
��ɭ�ֲ��ĸо����ſ��кܶ����������š����������Ƕ����ˡ�
LONG
        );
        set("outdoors", "city");
        set("exits", ([
        "south" : __DIR__"bdj3",
        ]));
        set("objects", ([
   __DIR__"npc/hchshw1" : 3,
   __DIR__"npc/hchshw2" : 3,
   __DIR__"npc/hchshw3" : 3,
 

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
