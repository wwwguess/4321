//ROOM: d/suzhou/wroad4.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"�����"NOR);
	set("long", @LONG
	  ������������ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ��֪����ʲô
ԭ�򡣶���Զ��������������������һ��ˮ�������Ժ�ˮ�����߾͵������ˡ��ϱ���
��һ���ӻ��̣�������һЩ������
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"wgate",
		"north" : __DIR__"sjin",
		"south" : __DIR__"zhpu",
		"east" : __DIR__"wroad3",
]));
	set("objects", ([
		__DIR__"npc/ren" : 1,
]));
	setup();
}





