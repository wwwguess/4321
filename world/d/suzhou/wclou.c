//ROOM: d/suzhou/wclou.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;   

string look_scene();

void create()
{
	set("short", MAG"西城楼"NOR);
	set("long", @LONG
	  这是苏州西门城楼，从这儿可以看见(look)远处的情景(scene)。许多游人
喜欢到这儿眺望。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"down" : __DIR__"wgate",
	]));
	set("objects", ([
		__DIR__"npc/ren" : 2,
]));                              
	set("item_desc", ([
		"scene" : (: look_scene :),
]));
	setup();
}           

string look_scene()
{
	return YEL"远处草长莺飞，游人	如织，好一派美丽的景象。你禁不住想高歌一曲。"NOR;
}





