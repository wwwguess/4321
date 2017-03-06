//ROOM: d/suzhou/shizx.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"市中心"NOR);
	set("long", @LONG
	这儿就是苏州城的市中心了，来来往往的行人不停的经过你身边。一些花花
公子，阔少恶霸带着家奴横行霸道，也有一些卖艺人在辛苦地卖艺。西边十分热闹，
不知道有什么事。比较而言，北边就太安静了。东边也挺热闹的，那边有天下闻名的
八仙酒楼。南边传来一些姑娘的笑声，让人十分好奇。
LONG
	);
	set("no_sleep_room",1);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"wroad1",
		"north" : __DIR__"nroad1",
		"south" : __DIR__"sroad1",
		"east" : __DIR__"eroad1",
]));
	set("objects", ([
		__DIR__"npc/hhgz" : 1,
		__DIR__"npc/myren" : 1,
		__DIR__"npc/girl" : 1,
]));
	setup();
}





