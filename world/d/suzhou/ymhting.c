// Room: /d/suzhou/ymhting.c
//by dwolf
//97.11.4 

#include <ansi.h>         
#include <room.h>
inherit ROOM;

void create()
{
	set("short", MAG"���ź���"NOR);
        set("long", @LONG
	  ���������ź����������м������ӣ�һ�����ӣ�����һ�������֪������
��������ͼ�λ�������졣
LONG
	);

	set("exits", ([
		"south" : __DIR__"ymzting",
		"east" : __DIR__"shufang2",
	]));        
	
	set("objects", ([
		__DIR__"npc/surr" : 1,
		__DIR__"npc/ster" : 1,
		__DIR__"npc/lhxiu" : 1,
		/*__DIR__"npc/gsnan" : 1,*/
	]));

	setup();
}


