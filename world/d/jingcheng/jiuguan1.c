#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"����ɾƼ�"NOR);
	set("long", @LONG
����һ��ͨ�����ŵľƹݡ����ﲻ����Ӧ���صĸ������ƣ�
��Ҳ�������������������ĸ������ơ�
LONG         
	);
	set("objects", ([ 
        __DIR__"npc/waiter3" : 1,
      ]));

	set("exits", ([ 
 "west" :__DIR__"baih1", 
 
	]));
	setup();
	replace_program(ROOM);
}

