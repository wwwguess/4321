#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"뷽�������"NOR);
	set("long", @LONG
���̣�Ҳ���ǻ����̣����Ƴ�ʱ���Ѿ��������й����ʵ۱��š���
�������������ķ��룬������ʿ�ھ��ǽ����Լ��Ľ��á���
���ڵ����ǵ����Ĺ��̣������Ȼ���������Ѵ��г�Խ���̵����ƣ�
���̶����������䡣
LONG         
	);
	
	set("objects", ([ 
        __DIR__"npc/shenfu" : 1,
      ]));

	set("exits", ([ 
 "east" :__DIR__"ql1",
 	]));
	setup();
	
}

