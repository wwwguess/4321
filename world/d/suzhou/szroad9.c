//ROOM: /d/suzhou/szroad9.c
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
		"east" : __DIR__"szroad8",
		"west" : "/d/yaowangu/start",
]));
	setup();
	replace_program(ROOM);
}
