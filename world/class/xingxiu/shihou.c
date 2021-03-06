#include <ansi.h>
// shihou.c 狮吼子

inherit NPC;
inherit F_MASTER;

string ask_me();
void consider();

void create()
{
	set_name("狮吼子", ({ "shihou zi", "shihou" }));
	set("title",MAG "星宿派" NOR + YEL "邪士" NOR);
        set("nickname", RED "星宿派二师兄" NOR);
	set("long", 
		"他就是丁春秋的二弟子狮吼子。\n"
		"他三十多岁，狮鼻阔口，一望而知不是中土人士。\n");
	set("gender", "男性");
	set("per", 13);
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("dex", 22);
	
	set("max_kee", 500);
	set("max_gin", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 20);
	set("combat_exp", 200000);
	set("score", 30000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );

	set_skill("force", 60);
	set_skill("huagong-dafa", 40);
	set_skill("dodge", 40);
	set_skill("zhaixinggong", 60);
	set_skill("strike", 70);
	set_skill("xingxiu-duzhang", 40);
	set_skill("parry", 60);
	set_skill("staff", 70);
  	set_skill("tianshan-zhang", 50);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu-duzhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "xingxiu-duzhang");

	create_family("星宿派", 2, "弟子");

	setup();
  	//carry_object("/clone/weapon/gangzhang")->wield();
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
        if ( (int)ob->query("shen") >=100 && ((fam = ob->query("family")) && fam["master_id"] == "shihou zi"))
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
        command("exert qisuck " + target->query("id"));
}
