#include <ansi.h>
// yu.c 俞莲舟

inherit NPC;
inherit F_MASTER;

void heal();
void create()
{
        set_name("俞莲舟", ({ "yu lianzhou", "yu" }));
       set("nickname", RED "武当二侠" NOR);
        set("long",
                "他就是张三丰的二弟子俞莲舟。\n"
                "他今年五十岁，身材魁梧，气度凝重。\n"
                "虽在武当七侠中排名第二，功夫却是最精。\n");
        set("title",RED "武当派" NOR + GRN +"真人" NOR);
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("kar", 28);

        set("max_kee", 2100);
        set("max_gin", 1800);
        set("force", 2100);
        set("max_force", 2100);
        set("force_factor", 60);
        set("combat_exp", 2700000);
        set("score", 40000);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set_skill("force", 170);
        set_skill("taiji-shengong", 150);
        set_skill("dodge", 150);
        set_skill("tiyunzong", 140);
           set_skill("cuff", 100);
        set_skill("taiji-quan", 140);
	set_skill("move", 140);
        set_skill("parry", 160);
        set_skill("sword", 170);
        set_skill("taiji-jian", 160);
//      set_skill("taoism", 80);
      set_skill("literate", 110);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
             map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 2, "弟子");

        setup();
       carry_object("/obj/weapon/gangjian")->wield();
       carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "武当派")
	{
		command("say 我只收本门弟子，"+ RANK_D->query_respect(ob) + "可先拜我徒谷虚");
		return;
	}
        command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +
                "我辈中人，今天就收下你吧。");
        command("recruit " + ob->query("id"));
        this_player()->set("class", "taoist");
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title",RED "武当派" NOR + GRN +"道长" NOR);
        else
	        this_player()->set("title",RED "武当派" NOR + GRN +"女道长" NOR);
}

void init()
{

        object ob;
        mapping fam;

        ::init();

        ob = this_player();
        if ( (int)ob->query("bellicosity") >200 && ((fam = ob->query("family")) && fam["master_id"] == "yu lianzhou"))
	{
		command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
		command("expell "+ ob->query("id"));
	}
}		

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
		command("enforce 50");
                return;
        }

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}
