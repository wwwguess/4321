#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���˺���" NOR);
	set("long", @LONG
һ�����̾�������Զ�����죬������Զû�о�ͷ��
�˺��в�ʱ�йٴ�����ͨ������������ߺ������Ļ�ȭ����
LONG
	);
	set("exits", ([ 
  "south"  : __DIR__"rhztosz2.c",
  "north" : __DIR__"rhztosz0",
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

