//ROOM: /d/suzhou/szroad7.c
//by dwolf
//97.11.5

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"�����"NOR);
	set("long", @LONG
������һ�����׵�С���ϣ�Զ���ܷ񿴵�ɭ�֣���ϡ���������޵ĺ�������·����
����������������֡����߾������ݳ��ˡ�·�Ͽ��Կ���һЩȥ���Ե��ˡ�
LONG 
	);
	set("exits", ([   
		"north" : __DIR__"szroad8",
		"east" : __DIR__"szroad6",
		"west" : "/d/road/rjltosz1",
]));
	setup();
	replace_program(ROOM);
}
