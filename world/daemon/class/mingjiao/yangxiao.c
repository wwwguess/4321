// yangxiao.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("杨逍", ({ "yang xiao", "yang" }));

        set("title",GRN "明教" NOR + YEL +"光明左使" NOR);
        set("long",
"明教光明左使。\n");
        set("gender", "男性");
        set("age", 36);
        set("attitude", "peaceful");
        set("cor", 38);
        set("str", 27);
        set("int", 28);
        set("con", 28);
        set("kar", 25);
	set("per", 26);

        set("max_kee", 2000);
        set("max_gin", 1000);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 30);
        set("combat_exp", 2600000);
        set("score", 25000);

        set_skill("force", 150);
        set_skill("jiuyang-shengong", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("sword", 160);
        set_skill("taxue-wuhen", 120);
        set_skill("xiaoyao-jian", 160);
        set_skill("xiaoyao-zhang", 150);
        set_skill("strike", 120);
        set_skill("literate", 110);
        set_skill("shenghuo-shengong", 60);
        set_skill("qiankun-danuoyi", 50);

        map_skill("force", "jiuyang-shengong");
        map_skill("parry", "xiaoyao-jian");
        map_skill("sword", "xiaoyao-jian");
        map_skill("dodge", "taxue-wuhen");
        map_skill("strike", "xiaoyao-zhang");



        create_family("明教", 20, "弟子");

        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/mingjiao/obj/qingshan")->wear();

}
void attempt_apprentice(object ob)
{
	 if ((string)ob->query("family/family_name")!="明教" )
        {
                command("say 我不收外派弟子。");
                command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜颜垣。");
                return;
        }
        if ((int)ob->query_skill("jiuyang-shengong", 1) < 30) {
                command("say 你的九阳神功太低了，无法修习我的功夫。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在九阳神功上多下点功夫？");
                return;
        }

        if((int)ob->query("betrayer")>=10)
        {
                command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
                return;
        }
           command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
           command("recruit "+ob->query("id"));
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )

                      ob->set("title",GRN "明教" NOR + YEL +"旗主" NOR);
                        return;

}

void re_rank(object student)
{
                        student->set("title",GRN "明教" NOR + YEL +"旗主" NOR);
                        return;

}

