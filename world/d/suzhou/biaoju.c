// Room: /d/suzhou/biaoju.c
// by dwolf
//97.11.4 
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"��Զ�ھ�"NOR);
	set("long", @LONG
	������һ���ṹ��ΰ�Ľ���ǰ������ʯ̳�ϸ�����һ�����ɶ�ߵ���ˣ���
������Ʈ����������ý�������һͷ������צ�ķ������������������ơ���������
��д�š���Զ�ھ֡��ĸ���ƴ��֣������������վ��Ƿ�����ڴ������������ʣ���
�����������Ű��ء�
LONG
	);

	set("exits", ([
		"south" : __DIR__"wroad3",
		"north" : __DIR__"lwchang",
		"west" : __DIR__"qxku",
	]));

	set("objects", ([
		__DIR__"npc/fighter" : 2,
	]));

	setup();
	replace_program(ROOM);
}

