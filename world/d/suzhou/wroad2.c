//ROOM: d/suzhou/wroad2.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"�����"NOR);
	set("long", @LONG
	  ������������ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ��֪����ʲô
ԭ�򡣶������ַǳ���������һ��С���ӣ��ƺ���Щ�ڰ������˹ֵ��ĵġ���������
��ȥ�ĺá����߾����ĵģ��ϱ���һ����Ժ���Ŷ��Ϸ�����"����ի"�������֣�����
������������
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"wroad3",
		"north" : __DIR__"xxiang1",
		"south" : __DIR__"shuyuan",
		"east" : __DIR__"wroad1",
]));
	set("objects", ([
		__DIR__"npc/ren" : 1,
]));
	setup();
}





