// Npc: /kungfu/class/shaolin/cheng-shi.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("澄识", ({
		"chengshi luohan",
		"chengshi",
		"gongde",
		"luohan",
	}));
	set("long",
		"他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
		"太阳穴高高鼓起，似乎身怀绝世武功。\n"
	);


	set("title", HIR "少林" NOR + CYN "般若堂" NOR + RED "罗汉" NOR);
	set("nickname", GRN "功德" NOR + MAG "罗汉" NOR);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("per", 18);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("kar", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 70);
	set("combat_exp", 1700000);
	set("score", 10000);

	set_skill("force", 120);
	set_skill("hunyuan-yiqi", 120);
	set_skill("dodge", 115);
	set_skill("shaolin-shenfa", 120);
	set_skill("claw", 120);
	set_skill("yingzhua-gong", 120);
	set_skill("parry", 110);
	set_skill("buddhism", 85);
	set_skill("literate", 85);
	set_skill("blade", 120);
	set_skill("xiuluo-dao",115);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("claw", "yingzhua-gong");
	map_skill("parry", "xiuluo-dao");
	map_skill("blade","xiuluo-dao");

	prepare_skill("blade","xiuluo-dao");
	prepare_skill("claw", "yingzhua-gong");

	create_family("少林派", 37, "弟子");

	setup();

	carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/class/shaolin/chengb.h"

