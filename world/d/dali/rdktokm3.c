#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���ɽ����ɽ��" NOR);
	set("long", @LONG
�������ڹ��˺��ɽ�ˡ����Ҫ�ٹ�һ�οɲ����ס�
LONG
	);
	set("exits", ([ 
  "northup"  : __DIR__"rdktokm2",
  "south" : __DIR__"rdktokm4",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

