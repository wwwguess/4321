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
�������߾ͽ������ݸ��ؽ��ˡ�
LONG
	);
	set("exits", ([ 
  "south"  : __DIR__"rhztosz1.c",
  "north" : "/d/quanzhou/qzroad3",
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

