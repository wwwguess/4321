//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"��ˮ��ջ"NOR);
	set("long", @LONG
��ˮ��ջ�ǳ���ɽ������������һ�ҿ�ջ����Щ���ض����ɹ�Ƥë���˲�
������һ�㶼Ҫ�����ЪЪ�ţ����������ϰ׸ɡ������С��Ҳ�����飬
һ̤���ţ���С�������ڵ�ӭ��������
LONG         
	);

	set("exits", ([ 
 "southwest" :"/d/road/rfttocbs1",
 
	]));   
	set("objects", ([
	__DIR__"npc/waiter2.c" : 1,
]));
	setup();
	
}

