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
��������Կ������಻�ϵ�ɽ�����Ǿ�������֮�׵�̩ɽ��
LONG
	);
	set("exits", ([ 
  "west"  : __DIR__"jinan",
  "east" : __DIR__"rjntopl1",
  "northup" : "/d/taishan/daizong",
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

