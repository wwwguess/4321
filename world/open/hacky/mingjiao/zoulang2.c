// zoulang2.c ����
// by yuer


#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
	������һ�������ϣ���������������������ҩƷ�⡣
LONG
	);

	
	set("exits", ([
	
		"north" : __DIR__"yaoping",
		"west" : __DIR__"zoulang",
		"east" : __DIR__"liangong",		     
	]));
	setup();
}


