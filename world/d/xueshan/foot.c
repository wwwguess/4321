// foot.c
//by dwolf  
  
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "雪山山脚");
	set("long", @LONG
	  你在森林中七绕八拐，竟然来到了雪山脚下。只见雪山高耸入云，峰顶好
象有一家庄园隐隐约约出现在雪地中。
LONG
	);

	set("exits", ([
		"north" : __DIR__"forest5.c",
	 ]));
}            

void init()
{
	add_action("do_climb", "climb");    
//	add_action("do_push", "push");
}      

int do_climb(string arg)
{
        object me;
        object obj;
        object ob;
        ob = this_player();
        
        if ( !arg || arg != "up")
                return notify_fail("你要爬什麽?\n");
        
        me=this_player();
        
        if ( ((int)me->query_skill("dodge") < 100) ) { 
                tell_object(me, "你轻功太低，爬不上去。\n");
                return 1;
        }

        else if( ((int)me->query("kee")<500))
             {tell_object(me, "你体力不太够喔！\n");  

		return 1;
             }
 
        me->receive_damage("gin",50);
        me->receive_damage("kee",50);
        message_vision("$N手脚并用，慢慢地往上爬。\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("$N终于爬了上去。\n",me);
                this_player()->move(__DIR__"road1");
                message("vision","$N眼前是一条雪山小道.\n",
        environment(me),me);
                tell_room(__DIR__"road1","$N爬上了雪山。\n",me);
                return(1);
        }
        return(1);
}
/*                                      
int do_push(string arg)
{
	object me;
	me=this_player();
        if(!arg )
                return notify_fail("push <事>\n");
        if(query("exits/down")) return 0;
        if( arg=="grass") 
                        message_vision( "\n$N把草丛推开，露出一条向下的小路。\n",me);
	                set("exits/down",__DIR__"ywgu");
                        return 1;
}                   
*/
void reset()
{
    ::reset();
    if(query("exits/down"))
    	delete("exits/down");
}


                                                
