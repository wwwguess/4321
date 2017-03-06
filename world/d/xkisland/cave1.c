// Room: /u/dunno/cave/cave1.c
//cave: /u/dan/cave/cave1.c
//dan
inherit ROOM;
                                  
void create()
{
	set("short", "洞中");
	set("long", @LONG
千年古洞,四处留下岁月年痕.四壁已经斑斑驳驳,依稀可见有
些裂痕了.墙上象是用油彩绘着一些字画. 经仔细辨认
是－－赵客缦胡缨....
还绘着一青年书生，左手持扇，右手飞掌，神态甚是优雅潇洒。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"cave.c",
  "west" : __DIR__"cave2",
  "east" : __DIR__"cave24",
]));
	set("objects", ([ /* sizeof() == 2 */
   __DIR__"npc/npc2":1,
   __DIR__"npc/npc1":1,
]));
	set("no_fight", 1); 
        set("no_sleep_room",1);
        setup();
}

   
void init()
{
	add_action("do_studywall", "studywall");
}

int do_studywall()
{
	object me;  
        float exper;
        me = this_player();
	message_vision("$N专心地研究墙壁上的图形。\n", me); 
        if ((int)me->query_skill("literate", 1) >= 1)  
                  {
                       tell_object(me, "你似乎看不懂这些图形!\n");
                  }
        if ((int)me->query_skill("literate", 1) <= 0)
                 {
                       tell_object(me, "你发现这些图形似乎和武功有关!\n");
                  }
        if ((int)me->query_skill("force", 1) >= 100
         && (int)me->query_skill("literate", 1) <= 0
               ) 
                {
                        tell_object(me, "这些对于你来说太浅了！！！\n");
                 }
        if ((int)me->query_skill("force", 1) <= 99
         && (int)me->query_skill("literate", 1) <= 0 
               )       
        	{   
		int force = (int) me->query_skill("force", 1);
          	exper = to_float(me->query("combat_exp")); 
                if( !force || ( pow(to_float(force), 3.0) / 10.0 > exper) )
                  return notify_fail("你经验不足，快去练功.\n");
	        	me->receive_damage("gin", 20);
	        	me->improve_skill("force", (me->query("int")));
		        tell_object(me, "你的基本内功有所提高！！！\n");
	        }

	return 1;

}
