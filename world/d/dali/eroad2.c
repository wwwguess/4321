#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "��ɽС·" NOR);
	set("long", @LONG
��Χ���ǹ�ʯ���׵�ʯͷɽ��ż��Զ������һ����èͷӥ�У�
����ͷƤ���顣
LONG
	);
	set("exits", ([ 
  "northeast"  : __DIR__"eroad3",
  "west" : __DIR__"eroad1",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

