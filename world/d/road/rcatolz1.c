#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "ɽʯ�ٵ�" NOR);
	set("long", @LONG
һ��ɽʯ�̾͵Ĺٵ���������Զ�����죬������Զû�о�ͷ��
LONG
	);
	set("exits", ([ 
  "southeast"  : __DIR__"hanzhong",
  "west" : __DIR__"xxroad1",
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

