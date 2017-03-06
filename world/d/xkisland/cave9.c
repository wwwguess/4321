// Room: /u/dunno/cave/cave9.c
// /u/dan/room/cave/cave9.c
// dan
inherit ROOM;

void create()
{
	set("short", "洞窟");
	set("long", @LONG
千年古洞,四处留下岁月年痕.四壁已经斑斑驳驳,依稀可见有
些裂痕了.墙上象是用油彩绘着一些字画.四壁燃着巨烛,照亮整个
洞窟,室内东一处,西一处都是些武林人物. 墙壁上的字经仔细辨认
是－－闲过信陵饮.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cave8",
  "south" : __DIR__"cave10",
]));
	set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/npc13":1,
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
         
        if ((int)me->query_skill("cuff", 1) >= 100
         && (int)me->query_skill("literate", 1) <= 0 
               ) 
                {
                        tell_object(me, "这些对于你来说太浅了！！！\n");
                 }
        if ((int)me->query_skill("cuff", 1) <= 99
         
         && (int)me->query_skill("literate", 1) <= 0
               )       
        	{       
                        if( pow(to_float((int)me->query_skill("cuff", 1)), 3.0) / 10.0 >to_float(me->query("combat_exp")) )
                         return notify_fail("你经验不足，快去练功.\n");
	        	me->receive_damage("gin", 20);
	        	me->improve_skill("cuff", (me->query("int")));
		        tell_object(me, "你的基本拳法有所提高！！！\n");
	        }

	return 1;

}

