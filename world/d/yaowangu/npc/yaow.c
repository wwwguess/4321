// yaow.c 
//by dwolf
#include <ansi.h>
inherit NPC;

string ask_for_per();
string ask_for_con();

void create()
{
        set_name(RED"药王"NOR, ({ "yao wang", "wang" }));
        set("title", GRN"药王谷主"NOR);
        set("gender", "男性");
        set("long", "他就是医术高超的药王。看上去挺健康的。\n");
        set("age", 75);

        set("int", 30);

        set("kee", 1500);
        set("max_kee", 1500);
        set("gin", 1000);
        set("max_gin", 1000);
//        set("shen_type", 5);

        set("combat_exp", 500000);
        set("attitude", "friendly");

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 60);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 50);   
	set("inquiry", ([
		"美容" : (: ask_for_per :),
		"健美" : (: ask_for_con :),
	]));																																																								
     
	setup();
        add_money("gold", 1);
}           

string ask_for_per()
{     
	object me;
	me=this_player();
	if (me->query("per")>=26)
	{   if(me->query("gender")=="男性")	 
	      return "你已经很英俊了，不用再做手术了。\n";
	   else
	     return "你已经很漂亮了，不用了吧。\n";
		}					
	else
	{ 
	if( me->query_temp("mark/药王") || me->query("combat_exp") <= 500000) return 0;
       	this_player()->add("combat_exp", -10000);
	this_player()->add("per", 5); 
	me->set_temp("mark/药王", 1);
	me->set("mark/美容", 1); 
	set("busy", 5);
	message_vision("只见药王变戏法般的拿出一套工具，让$N
\n躺在一张石桌上，开始手术。\n", this_player()); 
	return YEL"想美容，好呀。--------哈哈，行了\n"NOR;
	}
}
   
string ask_for_con()
{       
	object me;
	me=this_player();
        if (me->query("con")>=29)
              return "你的根骨很好了,不用再做手术了。\n";       
        if( me->query_temp("mark/药王") ) return 0;
	this_player()->add("combat_exp", -15000);
	this_player()->add("con", 3); 
	set("busy", 5);
	me->set_temp("mark/药王");
	me->set("mark/健美");
	message_vision("只见药王变戏法般的拿出一套工具，让$N
\n躺在一张石桌上，开始手术。\n", this_player()); 
	return YEL"想健美，好呀。哈哈，行了\n"NOR;
}

