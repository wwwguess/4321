#include <ansi.h>
// zhaixing.c 摘星子

inherit NPC;
inherit F_MASTER;

string ask_me();
void consider();

void create()
{
	set_name("摘星子", ({ "zhaixing zi", "zhaixing" }));
	set("title",MAG "星宿派" NOR + YEL "邪士" NOR);
        set("nickname", RED "星宿派大师兄" NOR);

	set("long", 
		"他就是丁春秋的大弟子、星宿派大师兄摘星子。\n"
		"他三十多岁，脸庞瘦削，眼光中透出一丝乖戾之气。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 26);
	set("int", 28);
	set("con", 26);
	set("dex", 26);
	
	set("max_kee", 700);
	set("max_gin", 700);
	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 30);
	set("combat_exp", 300000);
	set("score", 40000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );

	set_skill("force", 70);
	set_skill("huagong-dafa", 50);
	set_skill("dodge", 70);
	set_skill("zhaixinggong", 100);
	set_skill("strike", 80);
	set_skill("xingxiu-duzhang", 80);
	set_skill("parry", 70);
	set_skill("staff", 70);
//	set_skill("tianshan-zhang", 60);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu-duzhang");
//	map_skill("parry", "tianshan-zhang");
//	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "xingxiu-duzhang");

	create_family("星宿派", 2, "弟子");

	setup();
//	carry_object("/clone/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") > -100) {
                command("say 我派讲究要心狠手辣，奸恶歹毒，你可做得不够呀！");
                return;
        }

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)this_player()->query("gender")!="女性")
        	this_player()->set("title",HIR "星宿派" NOR + GRN +"邪士" NOR);
        else
		this_player()->set("title",HIR "星宿派" NOR + GRN +"妖女" NOR);
}

void init()
{

        object ob;
        mapping fam;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") >=100 && ((fam = ob->query("family")) && fam["master_id"] == "zhaixing zi"))
        {
                command("say 你多次杀我同道中人，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
        }
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        if (random(2))
                command("exert qisuck " + target->query("id"));
        else
                command("exert jingsuck " + target->query("id"));
}
