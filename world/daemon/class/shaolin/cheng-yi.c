// Npc: /kungfu/class/shaolin/cheng-yi.c
// Date: YZC 96/01/19

#include <ansi.h>
inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("澄意", ({
		"chengyi luohan",
		"chengyi",
		"jieying",
		"luohan",
	}));
	set("long",
		"他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
		"太阳穴高高鼓起，似乎身怀绝世武功。\n"
	);


	set("title", HIR "少林" NOR + CYN "般若堂" NOR + RED "罗汉" NOR);
	set("nickname", GRN "接引" NOR + MAG "罗汉" NOR);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("per", 23);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("kar", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 2100);
	set("max_force", 2100);
	set("force_factor", 80);
	set("combat_exp", 1700000);
	set("score", 10000);

	set_skill("force", 120);
	set_skill("hunyuan-yiqi", 120);
	set_skill("dodge", 110);
	set_skill("shaolin-shenfa", 115);
	set_skill("cuff", 115);
	set_skill("luohan-quan", 120);
	set_skill("parry", 120);
	set_skill("sword", 115);
	set_skill("damo-jian",112);
	set_skill("buddhism", 95);
	set_skill("literate", 85);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");

	prepare_skill("sword", "damo-jian");
	prepare_skill("cuff", "luohan-quan");

	create_family("少林派", 37, "弟子");

	setup();

	carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/class/shaolin/chengb.h"

