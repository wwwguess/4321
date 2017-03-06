// Npc: /kungfu/class/shaolin/qing-wu.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("���ޱ���", ({
		"qingwu biqiu",
		"qingwu",
		"biqiu",
	}));
	set("long",
		"����һλ���ǿ����׳��ɮ�ˣ�����û���������ȫ���ƺ��̺�\n"
		"�������������һϮ�ײ��ڱ����ģ��ƺ������ա�\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 23);
	set("int", 17);
	set("con", 20);
	set("dex", 24);
	set("max_kee", 350);
	set("max_gin", 200);
	set("force", 350);
	set("max_force", 350);
	set("force_factor", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("move", 30);
	set_skill("hunyuan-yiqi", 30);
	set_skill("dodge", 30);
	set_skill("shaolin-shenfa", 30);
	set_skill("blade", 30);
	set_skill("cibei-dao", 30);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

	create_family("������", 40, "����");

	setup();

        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}


void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "����" )
	{
		command ("say �����ӷ�Ůʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
		return;
	}
        if( (string)ob->query("family/family_name") != "������" && ob->query("is_shaolin"))
        {
                command ("say �����ӷ�" + RANK_D->query_respect(ob) +"��Ȼ�Ѿ��ѳ����֣����ֺαػ����֡�");
                return;
        }
	
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say �����ӷ�ƶɮ�������������׼ҵ��ӡ��ˡ�");
	}
	command("say �����ӷ����գ����գ�");
	command("recruit " + ob->query("id"));
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		ob->set("is_shaolin", 1);
                if (this_player()->query("class")=="bonze")
                {
                        ob->set("title",HIR "����" NOR + CYN "Сɳ��" NOR);
                        return;
                }
                else
                {
                        ob->set("title",HIR "����" NOR + CYN +"�׼ҵ���" NOR);
                        return;
                }

}

void re_rank(object student)
{
                if (this_player()->query("class")=="bonze")
                {
                        student->set("title",HIR "����" NOR + CYN +"Сɳ��" NOR);
                        return;
                }
                else
                {
                        student->set("title",HIR "����" NOR + CYN +"�׼ҵ���" NOR);
                        return;
                }
}
