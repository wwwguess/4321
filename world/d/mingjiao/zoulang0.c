// zoulang0.c ����
// by yuer


#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
	������һ�������ϣ�����ͨ����Ժ�ıؾ�֮·��һ��
���ڵ���ֹ����
LONG
	);

	
	set("exits", ([
	
		"north" : __DIR__"houhuayuan",
		"south" : __DIR__"zoulang2",
     
	]));
	setup();
}


