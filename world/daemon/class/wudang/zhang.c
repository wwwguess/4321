// zhang.c 张三丰
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
void heal();
void create()
{
        set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
        set("nickname", HIR "邋遢真人" NOR);
        set("long",
                "他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
                "身穿一件污秽的灰色道袍，不修边幅。\n"
                "身材高大，年满百岁，满脸红光，须眉皆白。\n");
	set("title",RED "武当派" NOR + GRN "开山" NOR+ RED "祖师" NOR);
        set("gender", "男性");
        set("age", 100);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("kar", 30);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set("max_kee", 5000);
        set("max_gin", 3000);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 100);
          set("combat_exp", 5000000);
        set("score", 500000);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set_skill("force", 200);
        set_skill("taiji-shengong", 200);
	set_skill("move", 200);
        set_skill("dodge", 180);
        set_skill("tiyunzong", 180);
	set_skill("cuff", 200);
        set_skill("taiji-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 200);
        set_skill("literate", 200);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 1, "开山祖师");
        set("class", "taoist");

        setup();
        carry_object("/d/wudang/obj/zhenwu")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}


void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "武当派")
	{
		command("say 我只收本门弟子，"+ RANK_D->query_respect(ob) + "可先拜谷虚。");
		return;
	}
        if ((int)ob->query_skill("taiji-shengong", 1) < 50) {
                command("say 我武当派乃内家武功，最重视内功心法。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在太极神功上多下点功夫？");
                return;
        }
/*
        if ((int)ob->query("shen") <50000) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，先学做人");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
*/
        if (ob->query_int() < 30) {
                command("say 我武当派武功全从道藏悟出。");
                command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性是半点也马虎不得");
                command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可
挖，还是请回吧。");
                return;
        }
        command("chat 哈哈哈哈！！！！");
        command("chat 想不到老道在垂死之年，又觅得一个可塑之才，真是可喜可贺。")
;
        command("recruit " + ob->query("id"));
        this_player()->set("class", "taoist");
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title",RED "武当派" NOR + GRN +"真人" NOR);
        else
	        this_player()->set("title",RED "武当派" NOR + GRN +"女真人" NOR);
}

void init()
{

        object ob;
        mapping fam;

        ::init();
        add_action("give_quest","quest");
        ob = this_player();
/*
        if ( (int)ob->query("shen") <=2000 && ((fam = ob->query("family")) && fam["master_id"] == "zhang sanfeng"))
	{
		command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
		command("expell "+ ob->query("id"));
	}
*/
}		

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
		command("enforce 100");
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

int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

