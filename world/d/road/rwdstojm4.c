#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "����·" NOR);
	set("long", @LONG
һ�������������Զ�����죬������Զû�о�ͷ��
�����������߾��ǵ��������䵱ɽ��������ǽ��Źء�
LONG
	);
	set("exits", ([ 
  "south"  : __DIR__"jianmenguan",
  "north"  : __DIR__"rcatojm2",
  "northeast" : __DIR__"rwdstojm3",
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

