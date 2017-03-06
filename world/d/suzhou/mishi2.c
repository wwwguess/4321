//ROOM:/d/suzhou/mishi2.c
//by dwolf
//97.11.7              

#include <ansi.h>
inherit ROOM;          

void create()
{                           
	set("short", RED"武穆祠密室"NOR);
	set("long", @LONG
          你来到地下深处，只见四周点满了松明火把，一桶桶松油挂在上面，这些
火把已不知道点了多少年了。石室的地板上有本书，顶上挂着一把宝剑(ywsword)。
LONG
	);                                        

	set("objects", ([
		"/d/hangzhou/npc/obj/wmbook1" : 1,    
]));                         

	setup();
}      

void init()
{
	add_action("do_qu", "qu");
	add_action("do_swear", "swear");
}
               
int do_qu(string arg)
{
        object me;
	object ob;
	me = this_player();
        
        if ( !arg || arg != "ywsword" )
                return notify_fail("你要拿什麽?\n");  
	
	if(query_temp("mark/been_get")) 
		return notify_fail("宝剑已被拿走了。\n");
                       
        if ( ((int)me->query_skill("dodge") < 100) ) { 
                tell_object(me, "你轻功太低，拔不起来。\n");
                return 1;
        }

        else if( ((int)me->query("kee")<500))
             {tell_object(me, "你体力不太够喔！\n");  
              return 1;
             }
 
        me->receive_damage("gin",50);
        me->receive_damage("kee",50);
        message_vision("$N脚尖点地，用力一纵，想要取宝剑。\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("$N把宝剑取了下来。\n",me); 
		ob = new(__DIR__"npc/obj/ywsword");
                ob->move(this_player());   
		me->set("marks/ywsword",1);
                set_temp("mark/been_get",1);
	     return(1);
        }
        return(1);
}        
                                     
int do_swear(string arg)
{                 
	object ob,me;
	me = this_player();

	if( !arg || arg=="" ) return 0;    

        if( arg=="忠君"
	||  arg=="忠于皇帝") 
	{
		command("haha");
		message("vision", YEL"空中传来一阵大笑，：“好孩子，不愧是炎黄子孙。”\n"NOR, me);
		me->move("/d/suzhou/whci");
		tell_room(__DIR__"whci", YEL"$N忽然从天而降。\n"NOR); 
		return 1;      
	}
}
                                                





