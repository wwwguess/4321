//by dwolf
//97.11.13                 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɭ�ֱ�Ե");
	set("long", @LONG
	  ������ɭ�ֱ�Ե��Զ���������޵ĺ����������ľ���·����һ�ƾ�С��
������������һ�����������Ķ����������˭�����ɣ��߰������Ǹ�Ҳ�С�����
��˭����˭��Զ�������⣬����ҡ�
LONG
	); 
	set("exits", ([
		"north" : __DIR__"forest1.c",  
		"east" : "/d/suzhou/szroad9",
]));
	setup();
	replace_program(ROOM);
}
