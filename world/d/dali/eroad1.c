#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "�����Ƕ�" NOR);
	set("long", @LONG
����������Ƕ��������߾��ǵ�������ɽ·�ˡ�
LONG
	);
	set("exits", ([ 
  "east"  : __DIR__"eroad2",
  "west" : __DIR__"kunming",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

