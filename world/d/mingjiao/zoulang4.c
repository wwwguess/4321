// zoulang4.c ����
// by yuer


#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
	������һ�������ϣ�������ͨ���������õ��ʺ�
ǰ���������̽����ճ����֮����
LONG
	);

	
	set("exits", ([
		"south" : __DIR__"dadian",
		"north" : __DIR__"zoulang2",
	]));
	setup();
}


