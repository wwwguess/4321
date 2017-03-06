//ROOM:/d/suzhou/yuanlin4.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;            

void create()
{                           
	set("short", RED"苏州园林"NOR);
	set("long", @LONG
        	你走至荷花池的大桥上，见水如晶帘一般奔入，扶著藤栏过去，只
见水上落花愈多，其水愈清，溶溶荡荡，曲折萦纡，池边两行垂柳，杂著桃、杏，遮
天蔽日般，真无一些尘土。度过桥去则通往池心小亭。
LONG
	);                                        
	set("exits", ([
		"west" : __DIR__"yuanlin2", 
		"east" : __DIR__"yuanlin6",
]));             
	set("objects", ([
		__DIR__"npc/girl.c" : 1,
]));
	setup();
	replace_program(ROOM);
}
  

