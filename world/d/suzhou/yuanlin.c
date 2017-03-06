//ROOM:/d/suzhou/yuanlin.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"苏州园林"NOR);
	set("long", @LONG
        	一走入这个庭园，扑鼻而来的便是一股若有似无，但是又沁人心脾
的花香，庭园甚是宽敞，许多奇花异石错落其间，显是经过高手匠人的精心布置，西
边花丛间可看到朱红的屋角，一条石板小径沿著假山通往深处。
LONG
	);                                        
	set("exits", ([
		"north" : __DIR__"yuanlin2",  
		"east" : __DIR__"sroad2",
]));
	setup();
	replace_program(ROOM);
}
  

