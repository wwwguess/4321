//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"����¥��¥"NOR);
	set("long", @LONG
����¥�ǳ���������������һ�������ˡ����ﲻ�������о������
��ٹ��˵��ų����룬��ÿ��Ӵ��ŴӸ���Ľ�����������ˡ����
���˲��٣����Եÿ����ء�
LONG         
	);

	set("exits", ([ 
  "down" :__DIR__"zyl.c", 
 
	]));   
	set("objects", ([
	__DIR__"npc/guest1.c" : 4,
]));
	setup();
	
}

