#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"ˮ����"NOR);
	set("long", @LONG
������һ��ˮ���꣬��̨�ϰ����˸���ʱ���ʹ����������˵�����
���˿�ˮֱ�����ϰ�����һ�ѷ�����һ�߸Ҳ�Ӭ��һ��Ц���е��к�
�˿͡�
LONG         
	);   
	set("objects", ([
		__DIR__"t.c" : 1,
]));

	set("exits", ([ 
 "east" :"/d/jingcheng/baih6",
 	]));
	setup();
	
}

