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
  "southeast"  : __DIR__"eroad4",
  "southwest" : __DIR__"eroad2",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

