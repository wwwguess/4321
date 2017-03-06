//ROOM: d/suzhou/wroad2.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"西大街"NOR);
	set("long", @LONG
	  你走在西大街上，感到这里的街面要比别处的干净、整洁。不知道是什么
原因。东边热闹非常。北边是一条小巷子，似乎有些黑暗，让人怪担心的。看来还是
别去的好。西边静悄悄的，南边是一家书院，门洞上方大书"静心斋"三个大字，里面
传来读书声。
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





