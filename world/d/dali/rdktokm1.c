#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���ɽ����ɽ��" NOR);
	set("long", @LONG
һ�������������Զ�����죬������Զû�о�ͷ��
�Ϸ�һ����ɽ���������ǰ������Ǻ��ɽ��
LONG
	);
	set("exits", ([ 
  "northwest"  : __DIR__"rdktokm0",
  "southup" : __DIR__"rdktokm2",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

