//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"����¥"NOR);
	set("long", @LONG
����¥�ǳ���������������һ�������ˡ����ﲻ�������о������
��ٹ��˵��ų����룬��ÿ��Ӵ��ŴӸ���Ľ�����������ˡ����
һ̤���ţ���С�������ڵ�ӭ��������
LONG         
	);

	set("exits", ([ 
 "south" :__DIR__"xchjie2",
 "up" :__DIR__"zyl2.c", 
 
	]));   
	set("objects", ([
	__DIR__"npc/waiter2.c" : 1,
]));
	setup();
	
}

