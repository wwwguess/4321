//NPC:/d/suzhou/npc/fighter.c 
//by dwolf
//97.11.4
//changed by tlang
         
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"趟子手"NOR, ({ "tangzi shou", "shou", "fighter" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "他是镖局的弟子，武功虽然不太高，但对付一般土匪绰绰有余。\n");
	set("attitude", "heroism");

	set("str", 28);
	set("dex", 26);
	set("combat_exp", 20000);
	set("shen_type", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_skill("force", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 50);


        set("chat_chance_combat", 2);
	set("chat_msg_combat", ({
		"我们镖局威名远扬，信誉卓著。\n",
		"小兄弟，你可是来找我们保镖的？\n",
	}));
	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{   
        object ob; 
        ob = this_player();
	add_action("do_leave", "leave");

        ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 1, ob);    
}

void greeting(object me)
{
	object obj;
	obj = this_object();
	
	if( !me || environment(me) != environment() || !me->query("mark/护镖") )return;
       	obj->set_leader(me);
	me->set("mark/开始", 1);
	command("say 我们一路同行，请多指教。\n");
}

int do_leave()
{
	object ob,me;
	me=this_player();
	ob=this_object();

	if( !me->query("mark/成功") )
		return notify_fail("任务还没完成，我怎么能离开你？\n");
	ob->set_leader(0);
	destruct(ob);
	command("say 任务完成了，我该离开你了。\n");
		return 1;
}	



