//ROOM:/d/suzhou/yuanlin5.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;            

string* objects = ({
	"xiao",
	"teacup",
	"chahu",
});

void create()
{                           
	int i = random(sizeof(objects));
	set("short", RED"苏州园林"NOR);
	set("long", @LONG
        	你一进了小亭内，只觉异香扑鼻，那些奇草仙藤，越冷越苍翠，都
结了实，似珊瑚豆子一般，□垂可爱。亭内雪洞一般，清凉舒适，石桌上一个土定瓶，
中供著数枝菊花，旁边放了一只箫、一套茶瓯茶杯而已，似乎是让游人休息，娱乐而
设。远处峰峦迭翠，没有了出路。
LONG
	);                                        
	set("exits", ([
		"east" : __DIR__"yuanlin3",  
]));             
	set("objects", ([
		__DIR__"npc/obj/"+objects[i] : 1]));
	setup();
}
  

