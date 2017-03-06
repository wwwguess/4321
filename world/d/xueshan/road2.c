//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "雪山小道");
	set("long", @LONG
	  你走在静谧的山道上，感到一种惬意的舒心。你忍不住哈哈大笑几声。
"哈哈哈哈－－－－ "结果差点儿引起雪崩，你赶快停止大笑。这儿树木茂盛，怪石
林立，两道山峰间有许多蔓藤(vine)，后面似乎有什么。 头上的雪峰顶上似乎有一
个白点一闪。你怀疑自己眼睛花了。
LONG
	); 
	set("item_desc", ([
		"vine":
			"后面好象有亮光。你好象可以推开(push)它们.\n",
	]));
	set("exits", ([
		"southdown" : __DIR__"road1.c",
	])); 
	setup();
} 

void init()
{
	add_action("do_push", "push");          
	add_action("do_climb", "climb");
}
int do_push(string arg)
{
	if ( !arg || arg!="vine" ) 
		return notify_fail("你要推什么？\n");
	message_vision("$N用手拨开藤蔓。\n\n",
		 this_player());
	tell_room(__DIR__"door.c",this_player()->query("name") + "从外面挤了进来.\n");   
	this_player()->move(__DIR__"door.c");
	return 1;                   
}                        

int do_climb(string arg)
{             
        object me;
        object obj;
        object ob;
        ob = this_player();
        
        if ( !arg || arg != "雪峰" )
                return notify_fail("你要爬什麽?\n");
        
        me=this_player();
        
        if ( ((int)me->query_skill("dodge") < 150) ) { 
                tell_object(me, "你轻功太低，爬不上去。\n");
                return 1;
        }

        else if( ((int)me->query("kee")<1000))
             {tell_object(me, "你体力不太够喔！\n");  
                return 1;
             }
 
        me->receive_damage("gin",50);
        me->receive_damage("kee",100);
        message_vision("$N手脚并用，慢慢地往上爬。\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("$N终于爬了上去。\n",me);
                this_player()->move(__DIR__"hill2");
                message("vision","$N眼前是一个池子。n",
        environment(me),me);
                tell_room(__DIR__"hill2","$N爬上了雪峰。\n",me);
                return(1);
        }
        return(1);
}
  


                                                
