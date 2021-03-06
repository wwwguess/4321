#include <ansi.h>
// ding.c 丁春秋

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void consider();

void create()
{
	set_name("丁春秋", ({ "ding chunqiu", "ding" }));
	set("title",MAG "星宿派" NOR + YEL "开山" NOR + MAG "祖师" NOR);
        set("nickname", RED "星宿老怪" NOR);
	set("long", 
		"他就是星宿派开山祖师、令正派人士深恶痛绝的星宿老怪丁春秋。\n"
		"可是他看起来形貌清奇，仙风道骨。\n");
	set("gender", "男性");
	set("age", 60);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_kee", 4000);
	set("max_gin", 300);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("combat_exp", 1500000);
        set("shen",-150000);
	set("score", 400000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );

	set_skill("force", 100);
	set_skill("huagong-dafa", 150);
	set_skill("dodge", 150);
	set_skill("zhaixinggong", 150);
	set_skill("strike", 100);
	set_skill("xingxiu-duzhang", 150);
	set_skill("parry", 100);
	set_skill("staff", 100);
	set_skill("tianshan-zhang", 150);
	set_skill("literate", 80);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu-duzhang");
	map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "xingxiu-duzhang");

	create_family("星宿派", 1, "开山祖师");
	set("class", "taoist");

	setup();
//      carry_object("/clone/weapon/changjian")->wield();
}

void init()
{

        object me, ob;
        mapping fam;

        add_action("do_flatter", "flatter");
	add_action("give_quest","quest");
        ::init();

        ob = this_player();
        me = this_object();
        if ( (int)ob->query("shen") >=0 && ((fam = ob->query("family")) && fam["master_id"] == "ding chunqiu"))
        {
                command("say 你多次杀我同道中人，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
        }
}


void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -1000) {
                command("say 老仙越看你越象白道派来卧底的。");
                return;
        }

        if( me->query_temp("pending/flatter") ) {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
                return;
        } else {
                command("say 我星宿老仙比起古往今来的圣人怎么样啊？");
                message_vision("星宿老怪微闭双眼，手捻长须，一付等人拍马(flatter)的样子。\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("你说老仙什么？\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N大声说道：" + arg + "\n", this_player());
        if( strsrch(arg, "星宿老仙") >=0 && (strsrch(arg, "德配天地") >=0
         || strsrch(arg, "威震寰宇") >=0 || strsrch(arg, "古今无比") >=0 )) {
                command("smile");
                command("say 这还差不多。\n");
                command("recruit " + this_player()->query("id"));
	if((string)this_player()->query("gender")!="女性")
        	this_player()->set("title",HIR "星宿派" NOR + GRN +"邪士" NOR);
        else
		this_player()->set("title",HIR "星宿派" NOR + GRN +"妖女" NOR);
        } else {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
        }
        return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}

// 星宿老仙，德配天地，威震寰宇，古今无比

void consider()
{
        int i=random(4);
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        if (i==3)
                command("exert maxsuck " + target->query("id"));
        if (i==2)
                command("exert neilisuck " + target->query("id"));
        if (i==1)
                command("exert jingsuck " + target->query("id"));
        if (i==0)
                command("exert qisuck " + target->query("id"));
}
