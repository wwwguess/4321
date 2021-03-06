// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
void use_poison();

void create()
{
	set_name("蓝止萍", ({ "master dancer", "master", "dancer" }) );

	set("title", "晚月庄主");
	set("nickname", "回音仙子");
	set("gender", "女性");
	set("age", 22);
	set("long",
		"蓝止萍是一个十分出色的美女，她弹的一手琵\琶更是闻名千里，许\多\n"
		"王侯子弟，富商豪客都为她天下无双的美貌与琴艺倾倒。\n");
	set("attitude", "peaceful");
	set("class", "dancer");
	set("apprentice_available", 10);

	set("str", 21);
	set("int", 28);
	set("spi", 26);
	set("per", 30);
	set("cps", 30);

	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 18);
	set("shen_type",1);

	set("combat_exp", 1500000);
	set("score", 30000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		"蓝止萍嫣然一笑，一个转身迳自舞了起来，对眼前这场恶斗似乎全不放在心上。\n",
		"蓝止萍脚步轻移，翩翩地转了几个圈，回眸一笑。\n",
		"蓝止萍用手扶了扶自己的发簪，像是怕被对手碰歪似地。\n",
		"蓝止萍笑嘻嘻地拾起地上一片从" HIM "魔鞭翩珑" NOR "上落下的花瓣。\n",
		(: use_poison :),
		(: exert_function, "chillgaze" :),
	}) );

	set_skill("finger", 40);
	set_skill("sword", 70);
	set_skill("throwing", 100);
	set_skill("force", 70);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("literate", 100);
	set_skill("perception", 100);
	set_skill("music", 100);
//          set_skill("instruments", 150);
	set_skill("whip", 100);

	set_skill("stormdance", 100);
	set_skill("tenderzhi", 100);
	set_skill("iceforce", 100);
	set_skill("snowwhip", 90);

	map_skill("dodge", "stormdance");
        prepare_skill("finger", "tenderzhi");
	map_skill("finger", "tenderzhi");
	map_skill("force", "iceforce");
	map_skill("whip", "snowwhip");

	create_family("晚月庄", 1, "庄主");

	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);
	setup();

	carry_object(__DIR__"echowhip")->wield();
	carry_object(__DIR__"snake_sandal")->wear();
	carry_object(__DIR__"gold_belt")->wear();
	carry_object(__DIR__"bloody_dress")->wear();
}

void reset()
{
	delete_temp("learned");
	set("apprentice_available", 10);
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say 慢著，一个一个来。");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say 本庄主今天已经收了十个弟子，不想再收徒了。");
	}
}

void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "女性" )
		command("say 男人都不是好东西，滚开！");
	else {
		command("say 很好，只要你对本庄主忠心耿耿，好处是少不了的。");
		if( (int)ob->query("per") > 25 && (int)ob->query("age") < 20 )
			message_vision("$N暧昧地抚摸著$n的脸，说道：特别是像你这样的女孩 ....\n", this_object(), ob);
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "dancer");
	add("apprentice_availavble", -1);
}

void init()
{
  ::init();
  add_action("give_quest","quest");
}

void use_poison()
{
	object *enemy, ob;
	string msg;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	if( ob->query_condition("rose_poison") ) return;

	tell_object(ob, "你觉得脸上似乎沾上了什麽东西，伸手一摸却什麽也没有。\n");
	if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
		ob->apply_condition("rose_poison", 20);
}


// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一摇头，说道： 给我钱干什么？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N叹了口气，说道： 你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

