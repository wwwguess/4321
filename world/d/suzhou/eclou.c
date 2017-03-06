//ROOM: d/suzhou/eclou.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;   

string look_hill();

void create()
{
	set("short", MAG"����¥"NOR);
	set("long", @LONG
	  �������ݶ��ų�¥����������Կ���(look)Զ����ɽ��(hill)�������
��ϲ�������������
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"down" : __DIR__"egate",
	]));
	set("objects", ([
		__DIR__"npc/ren" : 1,
]));                              
	set("item_desc", ([
		"hill" : (: look_hill :),
]));
	setup();
}           

string look_hill()
{
	return YEL"Զ��ɽ��������ƣ�Ʈ��Ī�⡣\n"NOR;
}





