//by dwolf
//97.11.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"前院"NOR);
	set("long", @LONG
	  富贵山庄的前院布满了各种奇花异草，最多的是腊梅，奇怪的是这儿的
腊梅一年到头总开着，腊梅树脚下有些奇怪。院中有几个少年正在聊天。他们穿得很好，看上去也很快乐
。他们好象在争论什么。往北通向大厅，厅前有两个护院守着。
LONG
	);  
	set("exits", ([
		"south" : __DIR__"door.c",
		"north" : __DIR__"ting.c",
	]));                   
	set("objects", ([
		__DIR__"npc/guard2" : 2,
	]));
	setup();
}               
   
int valid_leave(object me,string dir)
{               
	object ob;     

	if( present("guard", environment(me)) )
    	{
        	if ( dir=="north" && !(int)me->query("mark/玉佩") ) 
	        	return notify_fail("护院伸手拦住了你,道：没有事别进去打扰我们庄主！\n");
	
		tell_room(__DIR__"guarden", YEL"护院道：小兄弟想见我们庄主，到后院时可叫一声。\n\n"NOR);   
      
  /*      if ( me->query("mark/玉佩") )
	me->delete("mark/玉佩");          */
    }
    return ::valid_leave(me,dir);
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg)
{
        object me,obj,ob;
     
        if ( !arg || arg != "腊梅树" )
                return notify_fail("你要搜什麽?\n");
        
        me=this_player();
		       
        if ( (int)me->query("combat_exp") <500000) {
                tell_object(me, "你什么也没搜到！\n");
                return 1;
        }

        else if( ((int)me->query("kee")<600))
             {
	tell_object(me, "你体力不太够喔！\n"); 
   		return 1;
             }
	me->receive_damage("gin",20);
        me->receive_damage("kee",60);
        message_vision("$N仔细搜索腊梅树脚。\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("搜到一把宝刀。\n",me);
   		ob = new(__DIR__"npc/obj/coldb");
		if(ob)
                  ob->move(me);            
                else
                   printf("error\n");
                return(1);
        }
        return(1);
}
        
