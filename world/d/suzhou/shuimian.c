//ROOM:/d/suzhou/shuidi.c
//by dwolf
//97.11.8 
         
#include <ansi.h>
inherit ROOM;    

void create()
{                           
	set("short", RED"荷花池水面"NOR);
	set("long", @LONG
   	 你来到荷花池水面，啊，终于见到了阳光，这里没有明显的出路。
不过池边的小栏杆似乎可以爬(climb)上去。
LONG                            
	); 
	set("outdoors", "shuidi");                                       
  	setup();
}              

void init()
{
        add_action("do_climb", "climb");
}

int do_climb()
{
        object me;
        me = this_player();

	tell_object(me,"你用尽剩余的力量抓住栏杆，往上爬。\n");      
	me->move(__DIR__"yuanlin4");  
        return 1;
}

