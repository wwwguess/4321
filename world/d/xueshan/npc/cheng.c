//NPC:/d/fgszhuang/npc/cheng.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;
string ask_for_yaowang();

void create()
{
	set_name(GRN"程灵素"NOR, ({ "cheng linsu", "cheng"}) );
	set("gender", "女性" );
	set("age", 25);
        set("long",
		"她是药王的关门弟子。正在研读医学。\n");
	set("combat_exp", 300000);
	set("attitude", "friendly");  
	set("per", 25);
	set("rank_info/respect", "美女");
	set("pursuer", 1);
	set("chat_chance",2);
        
	set("count", 1); 
	set("inquiry",([
                "药王"  : (: ask_for_yaowang :),
        ]));   
	setup();
	add_money("silver",1);   
	carry_object("/d/suzhou/npc/obj/cloth2.c")->wear();
}     

string ask_for_yaowang()
{
	object me;
	me = this_player();

	if(!(int)me->query("combat_exp")>=500000 )
	{
	return  "你的经验太低，还是算了吧。\n";
        } else {
	if(query("count")<1)                                                
        	return "师父今天已经为一个玩家做过手术了，你明天再来吧。\n";
	add("count", -1);
	command("say 家师就在里面，请进。\n");
	me->move("/d/xueshan/ywgu2");
		return "程灵素把门打开让你进去。又关上了。\n";  
	}
}
	