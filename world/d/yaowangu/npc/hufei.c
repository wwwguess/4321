//hufei.c
//by dwolf

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"胡斐"NOR, ({"hu fei", "hu" }));
        set("title", HIW"雪山飞狐"NOR);
        set("long",
                "他是一个个子高大，相当英俊，很吸引人。\n"
        );

        set("gender", "男性");
        set("rank_info/respect", "飞狐");

        set("attitude", "heroism");
        
        set("inquiry",([
                "苗若兰"  : "她在苏州，还是个小孩子.",
		"警幻仙子" : "你要见她，先得接我三招，你同意(nod)吗？", 
        ]));

        set("age", 30);
        set("shen_type", 10);
        set("str", 35);
        set("int", 30);
        set("con", 30);
        set("kar", 35);
	set("per", 30);
        set("max_kee", 3000);
        set("max_gin", 1000);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 300);
        set("combat_exp", 1000000);
        set("score", 1000000);
        set("apply/attack",  200);
        set("apply/defense", 200);

        set_skill("force", 200);
        set_skill("unarmed", 150);
        set_skill("blade", 200);
        set_skill("dodge", 250);
        set_skill("parry", 150);
      
        setup();
      
        carry_object(__DIR__"obj/hublade")->wield();
        carry_object(__DIR__"obj/hupi")->wear();
}

void init()
{
	::init();
	add_action("do_nod", "nod");
}


int do_nod()
{
	mapping guild;

	if( !this_player()->query("can_speak") || !(int)this_player()->query("mark/小霖") 
|| !this_player()->query("mark/手术") ) 
		return notify_fail("不行。");
	else {
/*	if( arg== "test" ) {*/
	say("\n胡斐点了点头，说道：很好，这是第一招....\n\n");
	COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
	if( (int)this_player()->query("kee") < 0 
	|| !present(this_player(), environment())) {
	say("胡斐叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
		return 1;
		}
		say("\n胡斐说道：这是第二招....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("胡斐「哼」地一声，说道：便是有这许\多不怕死的家伙....\n");
			return 1;
		}
		say("\n胡斐说道：第三招来了....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("胡斐叹道：可惜，最后一招你没通过，见不到仙子了。....\n");
			return 1;
		}
		say("\n胡斐哈哈大笑，说道：我这就带你去见仙子！\n\n");
		this_player()->move("/d/xueshan/heaven");
		this_player()->delete("mark/小霖");
			return 1;
	}
		return 0;
}


