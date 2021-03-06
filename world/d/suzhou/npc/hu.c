//NPC:/d/suzhou/npc/hu.c  
//by dwolf
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("杨康", ({ "yang kang", "yang" }));
        set("title",CYN "苏州" NOR + YEL "知府" NOR);
	set("gender", "男性");
	set("age", 43);
	set("str", 40);
	set("dex", 30);
	set("per", 27);
	set("long", @LONG
	  他就是杨康，苏州现任知府。熟悉他的人都很鄙夷他的为人。
LONG
	);
	set("combat_exp", 500000);
	set("shen_type", 20);
	set("attitude", "heroism");

	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("sword", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("leadership", 50);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 75);

	set("force", 700); 
	set("max_force", 700);
	set("force_factor", 30);

	setup();
	carry_object(__DIR__"obj/blade")->wield();  
	carry_object(__DIR__"obj/nuerh");
}

int recognize_apprentice(object ob)
{
        if ( (string)ob->query("family/family_name")=="朝廷" && (string)ob->query("wen-wu")=="wen")
                return 1;
	else
		return 0;
}
