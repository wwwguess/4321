//NPC: /d/suzhou/npc/tianss.c
// by dwolf          
//97.11.6
           
#include <ansi.h>
inherit NPC;

string ask_for_yupei();

void create()
{
        set_name(RED"苗若兰"NOR, ({"miao ruolan", "miao", "ruolan"}));
        set("title", YEL"天真女孩"NOR);
        set("long",
                "她是江南大侠苗人凤的宝贝女儿。她好象有什么事想托人办。\n"
        );

        set("gender", "女性");
        set("rank_info/respect", "美女");

        set("attitude", "peaceful");
        
        set("inquiry",([
                "玉佩"  : (: ask_for_yupei :),
        ]));   
	set("count", 1);

        set("age", 20);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
	set("per", 30);
        set("max_kee", 300);
        set("max_gin", 100);
        set("force", 100);
        set("max_force", 100);
        set("force_factor", 10);
        set("combat_exp", 15000);
        set("score", 1000);
        set("apply/attack",  10);
        set("apply/defense", 10);

        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
       
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
                BLK"苗若兰幽幽地说道：“爹爹在家一定很担心我。不知道有谁能给我捎个消息给他。”"NOR
        }) );

        add_money("silver", 50);
}

void init()
{
        add_action("do_decide", "decide");
}

string ask_for_yupei()
{
        object me;  

        me = this_player();
	
       if( !me->query("mark/玉佩"))  
	{
	        if ((int)me->query("combat_exp") <= 200000 )
                	return RED"这路上十分危险，你可不要拿自己的生命开玩笑。\n"NOR;        
       		if (query("count") < 1)
                	return "抱歉，你来晚了，玉佩已经给别人了，谢谢你的好意。";

       		add("count", -1);

       		me->set_temp("pending/yupei", 1);
        		return "玉佩？这位可是当真？你若决心已定(decide)，请告诉我。\n";
        }  else {
		return "你还没有为我送到，怎么又来了。";
	}
}

int do_decide()
{        
        object ob,me;
	me = this_player();

        if( !me->query_temp("pending/yupei") )
                return 0;

        message_vision(
                "$N点点头，决心闯一闯。\n\n"
                "$N接过玉佩，把它贴身藏好。\n\n"
                "$N对苗若兰一拱手，“告辞了”……\n\n",me);
	ob=new("/d/suzhou/npc/obj/yupei.c");
	ob->move(me);
        command("chat");
	command("admire");
        me->delete_temp("pending/yupei");
        me->add("combat_exp", 100);
	me->add("potential", 50); 
	me->set("mark/玉佩", 1);
		return 1;
}

