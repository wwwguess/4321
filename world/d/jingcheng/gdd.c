#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"�Ŷ���"NOR);
	set("long", @LONG
��ҵ��ϰ����֣������汲��͸���Ŷ����⡣����İ���Ҳ�ǹ�
�������ǽ�ϵĻ������ϵ��Σ����ϵ�ƿ������һ��������������
ô�䰮��
LONG         
	);  
	set("objects", ([
		"/d/jingcheng/npc/lin.c" : 1,
]));

	set("exits", ([ 
 "west" :__DIR__"chhgch",
 	]));
	setup();
	
}

