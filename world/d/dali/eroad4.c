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
����ͷƤ���� ���ˣ�ǰ����ǹ������ˡ�
LONG
	);
	set("exits", ([ 
  "northwest"  : __DIR__"eroad3",
  "northeast" : "/d/road/guiyang",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

