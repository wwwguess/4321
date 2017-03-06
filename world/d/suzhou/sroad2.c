//ROOM: d/suzhou/sroad2.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"南大街"NOR);
	set("long", @LONG
	    南大街乃是城里的繁华地段，一到晚上，一派灯红酒绿，尤为热闹。
笑声、歌声、琴声、箫声，汇成一片送入了你的耳朵，你不禁心猿意马，很想就此
停步享受一番。西边是苏州著名的园林。东边一条小巷子。传来小贩的吆喝声。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"yuanlin",
		"north" : __DIR__"sroad1",
		"south" : __DIR__"sgate",
		"east" : __DIR__"xxiang2",
]));                                   
	set("objects", ([
		__DIR__"npc/ren" : 1,
		__DIR__"npc/girl" : 1, 
]));
	
	setup();
}





