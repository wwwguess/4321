#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���ɽ" NOR);
	set("long", @LONG
�����������ǧ��ĺ��ɽ��ɽ�Ƹ߶��ա���������ȥ,
�������еĻ�ѩ�ڷ��Ű�����ѩ����Χ�ž���������Խ
��Խ�󣬻��ǸϿ��ɽ�ɡ�
LONG
	);
	set("exits", ([ 
  "northdown"  : __DIR__"rdktokm1",
  "southdown" : __DIR__"rdktokm3",
]));

	set("outdoors", "dali");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

