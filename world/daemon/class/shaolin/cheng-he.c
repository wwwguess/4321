// Npc: /kungfu/class/shaolin/cheng-he.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("澄和", ({
		"chenghe luohan",
		"chenghe",
		"jinshen",
		"luohan",
	}));
	set("long",
		"他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
		"太阳穴高高鼓起，似乎身怀绝世武功。\n"
	);


	set("title", HIR "少林" NOR + CYN "罗汉堂" NOR + RED "罗汉" NOR);
	set("nickname", YEL "金身" NOR + MAG "罗汉" NOR);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("per", 23);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 2200);
	set("max_force", 2200);
	set("force_factor", 100);
	set("combat_exp", 1800000);
	set("score", 20000);

	set_skill("force", 130);
	set_skill("hunyuan-yiqi", 130);
	set_skill("dodge", 130);
	set_skill("shaolin-shenfa", 130);
	set_skill("sword", 130);
	set_skill("fumo-jian", 135);
	set_skill("parry", 130);
	set_skill("buddhism", 110);
	set_skill("literate", 105);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("sword", "fumo-jian");
	map_skill("parry", "fumo-jian");
	prepare_skill("sword","fumo-jian");

	create_family("少林派", 37, "弟子");

	setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/class/shaolin/chengl.h"

