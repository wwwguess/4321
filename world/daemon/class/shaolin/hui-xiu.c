// Npc: /kungfu/class/shaolin/hui-xiu.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("慧修尊者", ({
		"huixiu zunzhe",
		"huixiu",
		"zunzhe",
	}));
	set("long",
		"他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，\n"
		"太阳穴微凸，双目炯炯有神。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("per", 21);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("kar", 20);
	set("max_kee", 600);
	set("max_gin", 400);
	set("force", 1600);
	set("max_force", 1600);
	set("force_factor", 50);
	set("combat_exp", 1100000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 105);
	set_skill("shaolin-shenfa", 105);
	set_skill("cuff", 105);
	set_skill("jingang-quan", 105);
	set_skill("staff", 106);
	set_skill("pudu-zhang", 106);
	set_skill("parry", 110);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("staff", "pudu-zhang");
	map_skill("parry", "pudu-zhang");

	prepare_skill("cuff", "jingang-quan");

	create_family("少林派", 38, "弟子");

	setup();

        carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}


#include "/class/shaolin/hui.h"

