#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���" NOR);
	set("long", @LONG
һ�������������Զ�����죬������Զû�о�ͷ��
�ڱ�����һ��С�������Ǵ�˵�е���ѩɽׯ����������
LONG
	);
	set("exits", ([ 
  "east"  : __DIR__"rfttocy1",
  "west" : __DIR__"rfttocy3",
  "north" : "/d/resort/smallroad",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
	object me = this_player();
	
        return;
}

