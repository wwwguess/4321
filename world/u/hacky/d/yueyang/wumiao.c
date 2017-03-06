// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>
#include <login.h>

inherit ROOM;

void create()
{
	set("short", "道法场");
	set("long", @LONG
	这里是和尚道士们给死人做法事（ｆａｓｈｉ）的大殿.  这里
香火很盛,看来江湖上仇杀不断, 和尚道士们大发死人财。一个法师正在
那里念经。
LONG
	);

	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");

	set("objects", ([
	__DIR__"npc/keeper" : 1,
	"/obj/magic/denotation.c":1,
	]));

	set("exits", ([
		"east" : __DIR__"beidajie2",
//		"up" : __DIR__"wumiao2",
//		"northwest": "/d/wizard/guest_room",
	]));
//       create_door("northwest", "竹门", "southeast", DOOR_CLOSED);  

	setup();   
    
}

void init()
     { add_action("do_fashi","fashi");
     }


int do_fashi(string arg)
{                
        object me;
   	object obj; 
	me=this_player();
        if (!arg) return notify_fail("你要为谁做法事？\n");
        obj = find_player(arg);
	if(!obj) return notify_fail("这个人不在线上....。\n");
        	if(obj->is_ghost() )	
                {if(me->query("gin")<110) return notify_fail("你的精力不够.\n");
                 if((me->query_skill("buddhism",1)<30) && (me->query_skill("daguanming",1)<30) && (me->query_skill("taoism",1)<10)) return notify_fail("你的佛法或道法不够.\n"); 

                obj->reincarnate();
		 obj->move(REVIVE_ROOM);
                 message_vision("$n突然一下出现在$N面前,诈尸呀!!!!!\n",me,obj);
        me->save();
	
                 
                 me->receive_damage("gin",100);
                 return 1;}
                 return notify_fail("不能超度活人.....\n");
}
