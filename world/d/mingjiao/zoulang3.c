// zoulang3.c ����
// by yuer


#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
	������һ�������ϣ�����ͨ��������,�����Ƿ��߿⣬
������ҩƷ�⡣
LONG
	);

	
	set("exits", ([
		"south" : __DIR__"fangjuku",
		"north" : __DIR__"wuqiku",
	 	 "west" : __DIR__"zoulang2",
		 "east" : __DIR__"yaopinku",		     
	]));
	setup();
}


