#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short", "��ɽ");
	set("long", @LONG
������ɽ�����棬���������
�����ƺ�������ĳ�ֶ����Х��,ʹ���е����
LONG
	);
	set("exits", ([ 
  "west"  : __DIR__"rcstoyt1",
  "eastup" : __DIR__"rcstoyt3",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

