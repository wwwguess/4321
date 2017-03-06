// wujiang.c 武将

inherit NPC;

void create()
{
        set_name("武将", ({ "wu jiang", "wu", "jiang" }));
	set("title","边关武将");
        set("gender", "男性");
        set("age", random(10) + 30);
        set("str", 25);
        set("dex", 16);
        set("long", "他是嘉峪关的守将。\n");
        set("combat_exp", 75000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("unarmed", 55);
        set_skill("force", 55);
        set_skill("sword", 55);
        set_skill("dodge", 55);
        set_skill("parry", 55);
        set_temp("apply/attack", 55);
        set_temp("apply/damage", 30);

        set("force", 300); 
        set("max_force", 300);
        set("force_factor", 10);

        setup();
        carry_object("/obj/weapon/gangjian")->wield();
        carry_object("/obj/cloth/tiejia")->wear();
}

int accept_fight(object me)
{
        command("say 老夫从不枉杀无名之人。");
        return 0;
}

