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
�����Ͼ���ͨ��ɽ�����ϸ �Ķɿ��ˡ��
LONG
	);
	set("exits", ([ 
  "northwest"  : __DIR__"cangzhou",
  "southeast" : __DIR__"rdktojd1",
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

