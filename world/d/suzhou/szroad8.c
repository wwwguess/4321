//ROOM: /d/suzhou/szroad8.c
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
		"south" : __DIR__"szroad7",
		"west" : __DIR__"szroad9",
]));
	setup();
	replace_program(ROOM);
}
