#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���" NOR);
����һ���������������ȥ���Կ������ݳ��ˣ��ⲻ�ɵ��㾫��һ�𣬼ӿ��˽Ų���

һ�������������Զ�����죬������Զû�о�ͷ��
LONG
	);
	set("exits", ([ 
  "southeast"  : __DIR__"rcatolz1",
  "northwest" : __DIR__"lanzhou",
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

