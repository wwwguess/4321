// Room: /u/dunno/cave/cave2.c
// /u/dan/room/cave/cave2.c
// dan
inherit ROOM;

void create()
{
	set("short", "洞窟");
	set("long", @LONG
千年古洞,四处留下岁月年痕.四壁已经斑斑驳驳,依稀可见有
些裂痕了.墙上象是用油彩绘着一些字画.四壁燃着巨烛,照亮整个
洞窟,室内东一处,西一处都是些武林人物. 墙壁上的字经仔细辨认
是－－吴勾霜雪明。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"cave3",
  "east" : __DIR__"cave1",
]));
	set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/npc6":1,
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
         if ((int)me->query_skill("force", 1) <= 99
         && (int)me->query_skill("literate", 1) <= 0 
               ) 
                {
                        tell_object(me, "这些对于你来说太深了！！！\n");
                 }
        if ((int)me->query_skill("force", 1) >= 150
         && (int)me->query_skill("literate", 1) <= 0 
               ) 
                {
                        tell_object(me, "这些对于你来说太浅了！！！\n");
                 }
        if ((int)me->query_skill("force", 1) <= 149
         && (int)me->query_skill("force", 1) >= 100 
         && (int)me->query_skill("literate", 1) <= 0 
               )       
        	{  
                 exper = to_float(me->query("combat_exp")); 
                 if( pow(to_float((int)me->query_skill("force", 1)), 3.0) / 10.0 > exper )
                  return notify_fail("你经验不足，快去练功.\n");
	        	me->receive_damage("gin", 20);
	        	me->improve_skill("force", (me->query("int")));
		        tell_object(me, "你的基本内功有所提高！！！\n");
	        }

	return 1;

}

