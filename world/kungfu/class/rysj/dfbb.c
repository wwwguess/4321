// dfbb.c 东方不败
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("东方不败", ({ "dong fang bu bai", "dong","dfbb" }));
	//set("nickname", "日月神教教主");
        set("title",HIR "日"+HIB"月"+HIY "神教" NOR + "教主");
	set("long", "他就是日月神教教主东方不败\n
		可是他看起来貌美如花,国色天香\n");
	set("gender", "中性");
	set("age", 30);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		("嘿嘿,武功不错啊\n"),
                (: exert_function, "kuihua" :),
		(: exert_function, "recover" :),
        }) );

	set("max_kee", 5000);
	set("max_gin", 5000);
	set("force", 8000);
	set("max_force", 5000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 1000000);

	set_skill("force", 100);
	set_skill("kuihua-shengong", 150);
	set_skill("dodge", 150);
	set_skill("mo-zhang-jue", 150);
	set_skill("unarmed", 100);
	set_skill("mo-jian-jue", 150);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("literate", 100);

	map_skill("force", "kuihua-shengong");
	map_skill("unarmed", "mo-zhang-jue");
	map_skill("parry", "mo-jian-jue");
	map_skill("sword", "mo-jian-jue");
	map_skill("dodge", "kuihua-shengong");
	create_family("日月神教", 1, "教主");
	setup();

	carry_object(__DIR__"obj/dress");
        carry_object(__DIR__"obj/flower_boot");
	carry_object(__DIR__"obj/needle")->wield();
}

void init()
{
	::init();
}

void attempt_apprentice(object me)
 {	
	command("say 我不收徒弟.\n");
 }


