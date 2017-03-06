// sample master.c code

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("���о�", ({"peng youjing", "peng", "youjing"}));
        set("title",MAG "ؤ��" NOR + YEL "�Ŵ�" NOR+ MAG "����" NOR);
        set("nickname", GRN "�Ʋ���ͷ" NOR);
        set("gender", "����");
        set("age", 50);
        set("long",
                "���о���ؤ���о����ɵ����죬���Ÿɾ�����������л��ӡ�\n"
                "�����Ϲ��Ŵ����Ц�ݣ�һ˫�۾����������ǵ�������\n");

        set("attitude", "peaceful");

        set("str", 24);
        set("int", 20);
        set("con", 24);
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
        set_skill("strike", 115);
        set_skill("xianglong-zhang", 110); // ����ʮ����
        set_skill("dodge", 125); // ��������
        set_skill("xiaoyaoyou", 115); // ��ң��
        set_skill("parry", 120); // �����м�
        set_skill("staff", 120); // ��������

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");

        prepare_skill("strike", "xianglong-zhang");

        create_family("ؤ��", 18, "�Ŵ�����");
        setup();
}

void attempt_apprentice(object ob)
{
        command("say �Ϸ���ͽ�ܣ�" + RANK_D->query_respect(ob) + "������ذɡ�
");
}
