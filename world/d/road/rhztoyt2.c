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
LONG
	);
	set("exits", ([ 
//  "southwest"  : "/d/choyin/n_gate",
  "northeast" : __DIR__"rhztoyt1",
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

