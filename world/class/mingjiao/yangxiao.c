// yangxiao.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("����", ({ "yang xiao", "yang" }));

        set("title",GRN "����" NOR + YEL +"������ʹ" NOR);
        set("long",
"���̹�����ʹ��\n");
        set("gender", "����");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 27);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

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
        set("combat_exp", 800000);
        set("score", 5000);

        set_skill("force", 120);
        set_skill("jiuyang-shengong", 100);
        set_skill("dodge", 150);
        set_skill("parry", 120);
        set_skill("sword", 140);
        set_skill("taxue-wuhen", 120);
        set_skill("xiaoyao-jian", 100);
        set_skill("xiaoyao-zhang", 100);
        set_skill("strike", 120);
        set_skill("literate", 110);
        set_skill("shenghuo-shengong", 50);
        set_skill("qiankun-danuoyi", 40);

        map_skill("force", "jiuyang-shengong");
        map_skill("parry", "xiaoyao-jian");
        map_skill("sword", "xiaoyao-jian");
        map_skill("dodge", "taxue-wuhen");
        map_skill("strike", "xiaoyao-zhang");



        create_family("����", 20, "����");

        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/mingjiao/obj/qingshan")->wear();

}
void attempt_apprentice(object ob)
{
	 if ((string)ob->query("family/family_name")!="����" )
        {
                command("say �Ҳ������ɵ��ӡ�");
                command("say " + RANK_D->query_respect(ob) + "��������ɿ��Ȱ���ԫ��");
                return;
        }
        if ((int)ob->query_skill("jiuyang-shengong", 1) < 30) {
                command("say ��ľ�����̫���ˣ��޷���ϰ�ҵĹ���");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ���ھ������϶��µ㹦��");
                return;
        }

        if((int)ob->query("betrayer")>=10)
        {
                command("say "+RANK_D->query_respect(ob)+"��α������壬���������㡣");
                return;
        }
           command("say �ðɣ�"+RANK_D->query_respect(ob)+"���Ҿ��������ˣ�\n");
           command("recruit "+ob->query("id"));
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )

                      ob->set("title",GRN "����" NOR + YEL +"����" NOR);
                        return;

}

void re_rank(object student)
{
                        student->set("title",GRN "����" NOR + YEL +"����" NOR);
                        return;

}

