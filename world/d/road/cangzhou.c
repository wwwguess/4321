#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "����" NOR);
	set("long", @LONG
�����Ǻӱ���������֮�磺���ݡ�������и������İ�����
֮�ң��°��ԡ�
������������߾͵����ϸ��ˣ������ͽ��뾩ʦ���������
�����������⡣

LONG
	);
	set("exits", ([
  "southeast" : __DIR__"rdktojd0", 
  "north"  : __DIR__"rjdtodk1",
  "southwest" : __DIR__"rjdtodk3",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

