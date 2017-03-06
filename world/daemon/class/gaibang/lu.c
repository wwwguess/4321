// sample master.c code

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("³�н�", ({"lu youjiao", "lu", "youjiao"}));
        set("title",MAG "ؤ��" NOR + YEL "�Ŵ�" NOR+ MAG "����" NOR);
        set("nickname", GRN "�ư���ͷ" NOR);
        set("gender", "����");
        set("age", 45);
        set("long",
                "³�н���Ȼ�书�㲻�ö�����֣������ڽ�����ȴ����������\n"
                "��Ϊ����ؤ�����������壬���¹������䣬��ú��߹������ء�\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 12);
        set("con", 25);
        set("dex", 20);

        set("kee", 2000);
        set("max_kee", 2000);
        set("gin", 100);
        set("max_gin", 100);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 120);

        set("combat_exp", 1200000);
        set("score", 20000);

        set_skill("force", 120); // �����ڹ�
        set_skill("huntian-qigong", 120); // ��������
        set_skill("strike", 125); // �����Ʒ�
        set_skill("xianglong-zhang", 120); // ����ʮ����
        set_skill("dodge", 120); // ��������
        set_skill("xiaoyaoyou", 120); // ��ң��
        set_skill("parry", 120); // �����м�
        set_skill("staff", 115); // ��������
	set_skill("blade", 120);
	set_skill("liuhe-dao", 110);
        set_skill("begging", 100);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
	map_skill("parry", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-dao");

        prepare_skill("strike", "xianglong-zhang");

        create_family("ؤ��", 18, "�Ŵ�����");
        setup();
}

void attempt_apprentice(object ob)
{
        mapping fam;
        if ((string)ob->query("family/family_name")!="ؤ��")
        {
		command("say ����ؤ����Ҫһ��һ������"+ RANK_D->query_respect(ob)+ "��Ҫ��һ����������");
                return;
        }
        if (ob->query("dai")<8)
        {
               	command("say " + RANK_D->query_respect(ob) + "�Ĵ������������ܰ��ұ���");
                return;
        }
        if (ob->query("dai")== 8 )
        {
        if ( (int)ob->query("int") >= 25 ) {
                command("say ����ؤ�������һ���Ը���Ϊ����" +
                RANK_D->query_respect(ob) + "�ϻ۹��ˣ��ƺ�����ѧؤ��Ĺ���");
                return;
        }
        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
                command("recruit " + ob->query("id"));
                this_player()->set("title",MAG "ؤ��" NOR + YEL +"�˴�" NOR + MAG "����" NOR);
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α�������С�л��أ�");
        return;
}
