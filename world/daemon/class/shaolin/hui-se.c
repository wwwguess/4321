// Npc: /kungfu/class/shaolin/hui-se.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("慧色尊者", ({
		"huise zunzhe",
		"huise",
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
	set("cor", 31);
	set("str", 30);
	set("int", 18);
	set("con", 28);
	set("kar", 25);
	set("max_kee", 620);
	set("max_gin", 400);
	set("force", 1600);
	set("max_force", 1600);
	set("force_factor", 70);
	set("combat_exp", 1130000);
	set("score", 6000);

	set_skill("force", 110);
	set_skill("hunyuan-yiqi", 110);
	set_skill("dodge", 110);
	set_skill("shaolin-shenfa", 110);
	set_skill("claw", 114);
	set_skill("longzhua-gong", 114);
	set_skill("blade", 110);
	set_skill("xiuluo-dao", 110);
	set_skill("parry", 110);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("claw", "longzhua-gong");
	map_skill("blade", "xiuluo-dao");
	map_skill("parry", "xiuluo-dao");

	prepare_skill("blade", "xiuluo-dao");

	create_family("少林派", 38, "弟子");

	setup();
	carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}


#include "/class/shaolin/hui.h"

