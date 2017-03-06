//
// /kungfu/class/xueshan/gelunbu.c  ���ײ�
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("���ײ�", ({ "gelunbu", "ge" }));
        set("long",@LONG
���ײ���ѩɽ���л���ɮ����ͷ�졣ͬʱ���µ��Ӵ����书��
��һ����ɫ���ģ�ͷ��ɮñ��
LONG
        );
        set("title", HIY "����" NOR);
        set("nickname", HIG "ɮ��ͷ��" NOR);
        set("gender", "����");
        set("age", 30);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 30);
        set("int", 20);
        set("con", 28);
        set("dex", 25);

        set("max_kee", 1000);
        set("max_gin", 1000);
        set("force", 1000);
        set("max_force", 1000);
        set("jiali", 20);
        set("combat_exp", 200000);
        set("score", 40000);

        set_skill("mizong-xinfa", 40);
        set_skill("literate", 30);
        set_skill("force", 80);
        set_skill("xiaowuxiang", 80);
        set_skill("dodge", 75);
        set_skill("shenkong-xing", 70);
        set_skill("parry", 60);
        set_skill("staff", 80);
        set_skill("xiangmo-chu", 70 );
        set_skill("hammer",50);
        set_skill("riyue-lun",40);
        set_skill("unarmed", 60);
        set_skill("yujiamu-quan", 60);



        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "xiangmo-chu");
        map_skill("staff", "xiangmo-chu");
        map_skill("hammer","riyue-lun");
        map_skill("unarmed","yujiamu-quan");

        create_family("ѩɽ��", 5, "����");
        set("class", "bonze");

        setup();

        carry_object("/d/xueshan/obj/b-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        carry_object("/d/xueshan/obj/senggun")->wield();

        add_money("silver",30);
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "����") {
                command("say ��ϰ�����ڹ���Ҫ����֮�塣");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }

        command("say �Ҿʹ���һЩ�书�ɣ�");
        command("recruit " + ob->query("id"));

        if((string)ob->query("class") != "bonze")       {
                ob->set("title","�׼ҵ���");
        }
        else    {
                ob->set("title",HIY"С����"NOR);
        }

        
}
