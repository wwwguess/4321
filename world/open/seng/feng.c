// feng.c 风清扬

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("风清扬",({"feng qingyang","feng"}));
        set("long",
                "华山前辈高人，\n"
                "他今年六十多岁。\n");
        set("nickname", RED "剑魔" NOR);
        set("title",GRN "华山派" NOR + YEL "隐侠" NOR);
        set("gender", "男性");
        set("age", 65);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);

        set("max_kee", 1800);
        set("max_gin", 800);
        set("force", 2000);
        set("max_force", 2000);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
	set("sen", 500);
	set("max_sen", 400);
        set("force_factor", 50);
          set("combat_exp", 5000000);
        set("score", 100000);

        set_skill("force",100);
        set_skill("huashan-neigong", 100);
        set_skill("dodge", 180);
        set_skill("huashan-shenfa", 180);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("dugu-jiujian",200);
        set_skill("literate", 150);
        set_skill("cuff", 110);
	set_skill("poyu-quan", 110);
        set_skill("strike", 110);
        set_skill("hunyuan-zhang", 110);

	map_skill("cuff", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "dugu-jiujian");
        map_skill("sword", "dugu-jiujian");

        prepare_skill("cuff", "poyu-quan");
	prepare_skill("strike", "hunyuan-zhang");

        create_family("华山派",17,"弟子");

        setup();

        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();
}

void attempt_apprentice(object ob)
{

	string title1;

	if ((string)ob->query("family/family_name")!="华山派") 
	{
		command("say 你非我派弟子，我不能收你。");
		return ;
	}

	if ((string)ob->query("gender")=="无性")
	{
		command("say 我不收无性人。");
		return ;
	}

        if ((int)this_player()->query_int() < 30 )
        {
                command("say 学习独孤剑主要要有好的悟性，"+RANK_D->query_respect(ob)+"资质不够。");
                return;
        }

        command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
        command("say 你今后可要惩恶扬善，旷扶正义！绝不可为非作歹，否则为师绝不会放过你的！\n");
	title1=ob->query("title");
        command("recruit "+ob->query("id"));
	ob->set("title", title1);
        
}

