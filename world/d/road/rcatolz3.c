#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "�ٵ�" NOR);
	set("long", @LONG
����һ����ʯ�ٵ�.��������ȥ���Կ������ݳ��ˣ��ⲻ�ɵ���
����һ�𣬼ӿ��˽Ų���
LONG
	);
	set("exits", ([ 
  "southeast"  : __DIR__"rcatolz2",
  "northwest" : __DIR__"lanzhou",
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

