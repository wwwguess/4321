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
��������Ա��һ�ҿ�ջ��
LONG
	);
	set("exits", ([ 
  "north"  : __DIR__"rfttocbs2",
  "northeast"  : "/d/xueshan/inn",
  "south" : __DIR__"rfttocbs0",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

int is_road() {
	return(1);
}

