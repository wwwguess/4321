//ROOM:/d/suzhou/yuanlin6.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;            

void create()
{                           
	set("short", RED"苏州园林"NOR);
	set("long", @LONG
        	  小亭的地板是以不同颜色的细石砌成各种图案。路面的图案组成
，全员是一个整体。但每幅图案又有独立的内容，总计花石子路上约有二十幅。一幅
幅观赏，美不胜收。小亭北边上的荷叶被拨开了，露出清澈的流水，水中似乎有什么
在动，也许你可以潜进(dive)水中看一看。
LONG
	);                                        
	set("exits", ([
		"west" : __DIR__"yuanlin4", 
]));             
	set("objects", ([
		__DIR__"npc/girl.c" : 1,
]));
	setup();
}              

void init()
{
	add_action("do_dive", "dive");
}

int do_dive(string arg) 
{
        object me;
        object obj;
        object ob;
        me=this_player();
        
        if ( ((int)me->query("kee") < 500) ||
             ((int)me->query("sen") < 300) ||
             ((int)me->query("force_factor") < 50 ) )
             { 
                        tell_object(me, "你这人还是别下去的好。\n"); 
                        return 1;
             }        
  	     
        me->receive_damage("kee",100);
        me->receive_damage("gin",10);
        message_vision("$N一头往水中扎了进去。\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("$N扎进了水中。\n",me);
                me->move("/d/suzhou/shuidi");
                tell_room(__DIR__"shuidi","上面露出微光,水流很急。\n");
                return(1);
        }
        return(1);  
}
  

