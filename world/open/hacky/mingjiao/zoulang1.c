// zoulang1.c ����
// by yuer


#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
	������һ�������ϣ������Ƿ�������������Ϣ�ҡ�
LONG
	);

	
	set("exits", ([
	
		"north" : __DIR__"xiuxishi",
		"west" : __DIR__"fanting",
		"east" : __DIR__"zoulang",		     
	]));
	setup();
}


