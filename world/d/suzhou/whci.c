//ROOM:/d/suzhou/whci.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;          

void create()
{                           
	set("short", RED"武穆祠"NOR);
	set("long", @LONG
        	 这是武穆公岳飞的祠堂，岳飞被秦桧害死后，他的躯体埋在杭州西
湖边，但祠堂却建在苏州。谁也不知道为什么。这里香火很旺，男男女女都来朝拜这位
民族英雄。你也许也该给他磕头(ketou)。
LONG
	);                                        
	set("exits", ([
		"west" : __DIR__"nroad1", 
]));             
	set("objects", ([
		__DIR__"npc/girl.c" : 1,    
		__DIR__"npc/woman.c" : 1,
]));
	setup();
}             

void init()
{
	add_action("do_ketou", "ketou");
}
int do_ketou(string arg) 
{
        object me;
        object obj;
        object ob;
        me=this_player();
        
        if ( ((int)me->query("force") < 500) ||
             ((int)me->query("score") < 100000) ||
             ((int)me->query("force_factor") < 50 ) )
	     { 
             		tell_object(me, "你恭恭敬敬地磕了一个头。\n"); 
			//me->add("chao_ting", 1);
			me->receive_damage("gin", 5);
                return 1;
             }

        else if( ((int)me->query("gin") < 60))
             {
			tell_object(me, "你好象有些累了，还磕头吗？\n");  
              return 1;
             }
 
        me->receive_damage("gin",20);
        me->receive_damage("kee",10);
        message_vision("$N磕着头，地面仿佛动了一下。\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("地面突然开了,$N从掉了进去\n",me);
                this_player()->move(__DIR__"mishi");
                tell_room(__DIR__"mishi","上面露出微光,你看见地上仿佛有本书。\n");
                return(1);
        }
        return(1);  
}
