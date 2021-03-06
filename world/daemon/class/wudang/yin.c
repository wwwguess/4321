#include <ansi.h>
// yin.c 殷梨亭 

inherit NPC;
//inherit F_MASTER;

void heal();
void create()
{
        set_name("殷梨亭", ({ "yin liting", "yin" }));
       set("nickname", RED "武当七侠" NOR);

        set("long",
                "他就是张三丰的最小的弟子殷梨亭。\n"
                "他今年三十四岁，长得英俊潇洒，但性格不够开朗。\n");
        set("title",RED "武当派" NOR + GRN +"真人" NOR);
        set("gender", "男性");
        set("age", 34);
        set("attitude", "peaceful");
        set("per", 26);
        set("str", 26);
        set("int", 28);
        set("con", 26);
        set("kar", 28);

        set("max_kee", 2000);
        set("max_gin", 1200);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 50);
        set("combat_exp", 2500000);
        set("score", 30000);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set_skill("force", 140);
        set_skill("taiji-shengong", 140);
        set_skill("dodge", 140);
        set_skill("tiyunzong", 140);
           set_skill("cuff", 130);
        set_skill("taiji-quan", 120);
        set_skill("parry", 140);
        set_skill("sword", 150);
        set_skill("taiji-jian", 150);
//      set_skill("taoism", 80);
        set_skill("literate", 80);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
           map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 2, "弟子");

        setup();
        carry_object("/d/wudang/obj/greyrobe")->wear();
        carry_object("/obj/weapon/gangjian")->wield();
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
		command("enforce 50");
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
