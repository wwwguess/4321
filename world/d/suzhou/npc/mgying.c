//NPC: /d/suzhou/npc/mgying.c
//by dwolf
//97.11.4

#include <ansi.h>

inherit NPC;

void heal();
void create()
{
        set_name(MAG"穆桂英"NOR, ({ "mu guiying", "mu" }));
        set("title", CYN "苏州" NOR + YEL "守将" NOR);
        set("gender", "女性");
        set("age", 23);
        set("str", 30);
        set("dex", 36);
	set("per", 35);
	set("ping", 5);

        set("long", "穆桂英可说是杨家头号女将。听说她和杨排风都是武当张三丰的高徒。\n");
        set("combat_exp", 800000);
        set("shen_type", 1);
        set("attitude", "heroism");

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

	set_skill("cuff", 100);
        set_skill("force", 100);
	set_skill("taiji-shengong",90);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
	set_skill("tiyunzong", 100);
	set_skill("taiji-quan", 100);
    	set_skill("taiji-jian",100);

        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
	map_skill("force", "taiji-shengong");

	prepare_skill("cuff", "taiji-quan");

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 80);

        set("max_kee", 1000);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 30);

        setup();
        carry_object(__DIR__"obj/gangjian")->wield();
        carry_object(__DIR__"obj/tiejia")->wear();
}

int accept_fight(object me)
{
        command(RED"say 本将军久未和江湖人动手过招了，今日就和你玩玩。"NOR);
        return 0;
}
int recognize_apprentice(object ob)
{
        if ( (string)ob->query("family/family_name")=="朝廷" && (string)ob->query("wen-wu")=="wu")
                return 1;
	else
		return 0;
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
                command("enforce 20");
                return;
        }

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}
