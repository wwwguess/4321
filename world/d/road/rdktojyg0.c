#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIR "�ƺӱ�" NOR);
	set("long", @LONG
�ƺӾ�����������ĺ�ˮ���ǲ���̫�󣬵�ˮ����ˢ�Ű�����
���ৡ����������Ǵ�����Զ������������ȥһ����Ƕɿ��ˡ�
LONG
	);
	set("exits", ([ 
  "southeast"  : __DIR__"lzdukoub",
  "northwest" : __DIR__"rdktojyg1",
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

