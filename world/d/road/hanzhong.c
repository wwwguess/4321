#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "����" NOR);
	set("long", @LONG
������Ǻ��У�����Ϊ���ұ���֮�ء�������Ƕ���ɽ��
�����͵����ݣ����������Ŷ������ˡ�
LONG
	);
	set("exits", ([ 
  "northeast" : "/d/road/rcatolz0",
  "northwest" : __DIR__"rcatolz1",
  "southwest" : __DIR__"rcatojm0",
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

