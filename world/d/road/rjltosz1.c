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
�����߾ͽ������ݸ��ؽ��ˡ�
LONG
	);
	set("exits", ([ 
  "east"  : "/d/suzhou/szroad7",
  "northwest" : __DIR__"rjltosz0",
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

