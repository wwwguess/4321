//lou2.c 
//by dwolf                   

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"吹雪二楼"NOR);
        set("long", @LONG
	  这儿完全是用檀香木打造的。一阵阵的檀香飘过来.使你心旷神夷。厅口
悬着一幅字画, 写道：“是非成败转头空，青山依旧在，几度夕阳红。”
LONG
        );
        set("exits", ([
        "down" : __DIR__"lou.c",
        ]));
      	setup();
}
            
/*void init()
{
    add_action("do_push", "push");
}

int do_push(string arg)
{
        object me;
	object obj;
	object ob;
	ob = this_player();
        
        if ( !arg || arg != "wall" )
                return notify_fail("你要推什麽?\n");
        
        me=this_player();
        
        if ( ((int)me->query("force") < 500) ||
             ((int)me->query("max_force") < 500) ||
             ((int)me->query("jiali") < 50 ) ) { 
                tell_object(me, "你出力不太够喔！\n");
                return 1;
        }

        else if( ((int)me->query("kee")<200))
             {tell_object(me, "你体力不太够喔！\n");  
              return 1;
             }
 
        me->receive_damage("gin",20);
        me->receive_damage("kee",60);
        message_vision("$N用力推活动的墙壁,墙壁动了一下\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("墙壁开了,$N从墙壁后面闪了出去\n",me);
                me->move(__DIR__"llou");
                message("vision","$N眼前是一座楼，上书“楼外楼.\n",environment(me),me);
        	tell_room(__DIR__"lou2","风一吹,墙壁又回到原处,把入口封住了\n");
                return(1);
        }
        return(1);
}
        */


                                                
