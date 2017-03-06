//ROOM:/d/suzhou/mishi.c
//by dwolf
//97.11.7              

string look_zi();          
#include <ansi.h>
inherit ROOM;          

void create()
{                           
	set("short", RED"武穆祠密室"NOR);
	set("long", @LONG
        	 这是武穆公岳飞的祠堂下面的密室，这里光线黑暗，你依稀看到
地面有本书。墙上仿佛有字(zi),不知道写些什么。地板有些松动，你敲了敲，仿佛
是空的。
LONG
	);                                        
	set("exits", ([
		"up" : __DIR__"whci", 
]));             
	set("objects", ([
		"/d/hangzhou/npc/obj/wmbook3" : 1,    
]));                         
	set("item_desc", ([
		"zi" :  (: look_zi :),
]));
	setup();
}      

string look_zi()
{
	return "武穆遗书，留于有缘人。\n\n 岳飞\n";
}                                     

void init()
{
	add_action("do_dig", "dig");
}


int do_dig(string arg)
{
        object me;
	object ob;
	me = this_player();
        
        if ( !arg || arg != "地板" )
                return notify_fail("你要挖什麽?\n");
                       
        if ( ((int)me->query_skill("unarmed") < 50) ) { 
                tell_object(me, "你臂力太低，挖不动。\n");
                return 1;
        }

        else if( ((int)me->query("kee")<200))
             {tell_object(me, "你体力不太够喔！\n");  
              return 1;
             }
 
        me->receive_damage("gin",15);
        me->receive_damage("kee",30);
        message_vision("$N拿出随身带的快刀，挖了起来。\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("$N忽然一脚踏空，掉了下去。\n",me); 
		me->move(__DIR__"mishi2");
                tell_room(__DIR__"mishi2", BLK"一个人从上面掉了下来。\n"NOR);
		me->receive_damage("kee", 100);
		me->receive_damage("gin", 50); 
	     return(1);
        }
        return(1);
}

