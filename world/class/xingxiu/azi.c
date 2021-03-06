// azi.c 阿紫

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string ask_me();
void consider();

void create()
{
	set_name("阿紫", ({ "azi" }));
	set("title",MAG "星宿派" NOR + YEL "妖女" NOR);
        set("nickname", RED "星宿派小师妹" NOR);
	set("long", 
		"她就是丁春秋弟子阿紫。\n"
		"她容颜俏丽，可眼神中总是透出一股邪气。\n");
	set("gender", "女性");
	set("per", 23);
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 24);
	
	set("max_kee", 300);
	set("max_gin", 300);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 10);
	set("combat_exp", 50000);
	set("score", 10000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );

	set_skill("force", 40);
	set_skill("huagong-dafa", 30);
	set_skill("dodge", 30);
	set_skill("zhaixinggong", 40);
        set_skill("strike", 30);
	set_skill("xingxiu-duzhang", 40);
	set_skill("parry", 20);
	set_skill("staff", 20);
//	set_skill("tianshan-zhang", 80);
  	set_skill("literate", 30);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu-duzhang");
//	map_skill("parry", "tianshan-zhang");
//	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "xingxiu-duzhang");

	create_family("星宿派", 2, "弟子");

	setup();
	carry_object("/d/xingxiu/obj/xxqingxin-san");
	carry_object("/d/xingxiu/obj/xxqingxin-san");
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") > 100) {
                command("say 我越看你越象白道派来卧底的。");
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
        if ( (int)ob->query("shen") >=100 && ((fam = ob->query("family")) && fam["master_id"] == "azi"))
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
