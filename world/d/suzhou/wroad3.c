//ROOM: d/suzhou/wroad3.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"�����"NOR);
	set("long", @LONG
	  ������������ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ��֪����ʲô
ԭ�򡣶���Զ����������������������ԭ��һ���ھ֣�����Զ�ھ֡����߾����ĵģ�
�ϱ�����һ��С�Ե꣬��ǰƮ��һ�鲼������"С�Ե�"�������֣����洫����������
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"wroad4",
		"north" : __DIR__"biaoju",
		"south" : __DIR__"xcdian",
		"east" : __DIR__"wroad2",
]));
	set("objects", ([
		__DIR__"npc/girl" : 1,
]));
	setup();
}





