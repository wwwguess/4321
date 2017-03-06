//ROOM: d/suzhou/wroad3.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"西大街"NOR);
	set("long", @LONG
	  你走在西大街上，感到这里的街面要比别处的干净、整洁。不知道是什么
原因。东边远处传来喧闹声。北边是中原第一大镖局－－威远镖局。西边静悄悄的，
南边是有一家小吃店，门前飘有一块布，大书"小吃店"三个大字，里面传来聊天声。
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





