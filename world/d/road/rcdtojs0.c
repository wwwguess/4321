#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���" NOR);
	set("long", @LONG
һ�������������Զ�����죬������Զû�о�ͷ��
�����ͽ��ɶ��ˣ����Ϸ����ǵ����š�
LONG
	);
	set("exits", ([ 
  "northeast"  : __DIR__"chengdu",
  "west" : __DIR__"rcdtojs1",
  "southwest"	: "/d/tangmen/road1",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
return;
}

