// Npc: /kungfu/class/shaolin/xuan-bei.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
	set_name("玄悲大师", ({
		"xuanbei dashi",
		"xuanbei",
		"dashi",
	}));
	set("long",
		"他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。他身材甚高，\n"
		"但骨瘦如柴，顶门高耸，双目湛然有神。\n"
	);


	set("nickname", CYN "达摩院" NOR + RED "主持" NOR);
        set("title", HIR "少林" NOR + MAG "圣僧" NOR);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
	set("max_kee", 1500);
	set("max_gin", 1000);
	set("force", 2400);
	set("max_force", 2400);
	set("force_factor", 150);
	set("combat_exp", 2400000);
	set("score", 500000);

	set_skill("force", 160);
	set_skill("hunyuan-yiqi", 160);
	set_skill("dodge", 160);
	set_skill("shaolin-shenfa", 160);
	set_skill("hand", 160);
	set_skill("claw", 160);
	set_skill("blade", 160);
	set_skill("sword", 160);
	set_skill("parry", 160);
	set_skill("qianye-shou", 160);
	set_skill("longzhua-gong", 160);
	set_skill("cibei-dao", 160);
	set_skill("damo-jian", 160);
	set_skill("buddhism", 150);
	set_skill("literate", 150);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "qianye-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("blade", "cibei-dao");
	map_skill("sword", "damo-jian");
	map_skill("parry", "cibei-dao");

	prepare_skill("hand", "qianye-shou");
	prepare_skill("claw", "longzhua-gong");

	create_family("少林派", 36, "弟子");

	setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "澄")
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎麽跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
		this_player()->set("title",HIR "少林" NOR + CYN "达摩堂" NOR + RED "弟子" NOR);
	}
	else
	{
		command("say " + RANK_D->query_respect(ob) + "，你辈份不合，不能越级拜师。");
		return;
	}

	return;
}

void init()
{
  add_action("give_quest","quest");
 }

#include "/class/shaolin/xuan1.h"
// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N双手合十，说道： 罪过罪过。\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N双手合十，说道： 善哉善哉，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

