// wangerm.c 王二麻

#include <ansi.h>

inherit NPC;
//inherit F_CLEAN_UP;

                                    
void create()
{
	set_name("王二麻", ({ "wang er ma", "wang",  }) );
	set("title", "精武馆泉州分馆武师");
	set("gender", "男性" );
	set("shen_type", 1);
	set("age", 40);
	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);

	set("no_clean_up",1);

	set("long",
		"这是整天笑咪咪的老板，虽然功夫不高，却也过得自在。\n" );

	set("combat_exp", 50000);
	set("attitude", "peaceful");
	set("chat_chance", 1);
	set("chat_msg", ({
		"王二麻说道: 这位英雄，您想进馆练武吗 ?\n",
	}) );

	set("max_kee", 700);
	set("max_gin", 400);
	set("force", 7000);
	set("max_force", 7000);
	set("jiali", 50);
	set("shen_type", 1);
                              
	set_skill("force", 60); 
	set_skill("unarmed", 100);
        set_skill("dodge", 100);
	set_skill("parry", 100);
	
	setup();
	

	carry_object("/obj/cloth")->wear();
}


int accept_object(object who, object ob)
{
	if(this_object()->query_temp("有人/mark"))
		{command("say 非常抱歉，武场爆满，请客官改日再来\n");
		return 0;
		}
	else
	{
		if (ob->query("money_id") && ob->value() >= 80000) 
		{
			tell_object(who, "王二麻笑眯眯：好，英雄请进馆。\n");
			who->set_temp("教钱了/mark",1);
			return 1;
		}
        }
	return 0;
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting())
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
	if(this_object()->query_temp("有人/mark"))
		command("say 非常抱歉，武场爆满，请客官改日再来\n");
	return ;
}
