#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", YEL"鲜花店"NOR);
	set("long", @LONG
     这里是文明京城的花店，店老板是京城出了名的美人－－美蚕娘。她英姿飒爽
楚楚动人 ，现在她正忙着招呼着来来往往的客人。店里摆满了五彩缤纷，争奇斗艳
的花卉。
LONG         
	);
        set("objects", ([
		__DIR__"npc/fsgirl.c" : 1,
]));
	set("exits", ([ 
 "east" :__DIR__"baih5",  
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

