#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "���" NOR);
	set("long", @LONG
����һ�����Ĵ��! @���������˺ܶ�.�Ա��кܶ�Ŀ�ջ�Ͳ��.ʱ����һƥƥ����
���۶���,����һ����,ԭ���ǹٸ��Ĳ�����ִ�й���!
LONG
	);
	set("exits", ([ 
  "west"  : __DIR__"rxstocd2",
  "east" : __DIR__"rxstocd4",
  "south": "/u/m/mic/mic2.c"
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
}

void init()
{	
        return;
}

