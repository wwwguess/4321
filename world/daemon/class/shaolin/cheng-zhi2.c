// Npc: /kungfu/class/shaolin/cheng-zhi2.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("澄志", ({
		"chengzhi luohan",
		"chengzhi",
		"guangming",
		"luohan",
	}));
	set("long",
		"他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
		"太阳穴高高鼓起，似乎身怀绝世武功。\n"
	);


	set("title", HIR "少林" NOR + CYN "般若堂" NOR + RED "罗汉" NOR);
	set("nickname", YEL "光明" NOR + MAG "罗汉" NOR);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("per", 21);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("kar", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("combat_exp", 1700000);
	set("score", 10000);

	set_skill("force", 120);
	set_skill("hunyuan-yiqi", 115);
	set_skill("dodge", 120);
	set_skill("shaolin-shenfa", 120);
	set_skill("finger", 110);
	set_skill("yizhi-chan", 110);
	set_skill("parry", 115);
	set_skill("staff",120);
	set_skill("wuchang-zhang",120);
	set_skill("buddhism", 85);
	set_skill("literate", 85);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "yizhi-chan");
	map_skill("parry", "wuchang-zhang");
	map_skill("staff", "wuchang-zhang");

	prepare_skill("finger", "yizhi-chan");
	prepare_skill("staff", "wuchang-zhang");

	create_family("少林派", 37, "弟子");

	setup();

	carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/class/shaolin/chengb.h"

