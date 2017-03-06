// sleep_room: /u/dan/room sleeproom.c
//dan

inherit ROOM;

void create()
{
    set("short", "休息室");
    set("long", @LONG
千年古洞,四处留下岁月年痕.四壁已经斑斑驳驳,依稀可见有
些裂痕了.墙上象是用油彩绘着一些字画.这里是休息室.墙壁
上写有入洞须知－－入洞所领悟武学均有经验限制。
                  切记！否则将走火入魔.
                                  ------岛主龙不凡
LONG
    );  
    
    set("exits", ([ /* sizeof() == 1 */
      "west" : __DIR__"cave.c",
      
    ]));
    set("sleep_room",1);  
    set("no_fight",1);
    set("no_clean_up", 0);

    setup();
    
}
  void init()
{
	object me;
	mapping skill_status;
	string *sname;
	int i, level; 
	float exper;

	me = this_player();

	exper = to_float(me->query("combat_exp"));

	if ( !(skill_status = me->query_skills()) ) return;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) 
	{
		level = skill_status[sname[i]];
		if( pow(to_float(level), 3.0) / 10.0 > exper 
		&& exper > 100.0
		&& sname[i] != "buddhism"
		&& sname[i] != "literate"
		&& sname[i] != "taoism" ) 
		{
			level = ceil( pow( exper*10.0, 0.333333) );
			me->set_skill(sname[i], level);
		}
	}
}
