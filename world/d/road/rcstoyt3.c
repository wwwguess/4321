#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short", "��ɽ");
	set("long", @LONG
�Ǹ�Զ����һƬ��ú�ɽ������ϰϰ��ʵ���Ǹ��õط���
���������ڿ���û����˼������һ�У���Ϊ������ϻ���û��
LONG
	);
	set("exits", ([ 
  "westdown"  : __DIR__"rcstoyt2",
  "eastdown" : __DIR__"rcstoyt4",
]));
       set("objects", ([
                "/obj/npc/tiger" : 3,
 ]) );


	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

