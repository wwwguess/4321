 // liangfa.c ����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����", ({ "liang fa", "liang" }));
        set("title",GRN "��ɽ��" NOR + YEL +"����" NOR);
        set("long",
                "��������Ⱥ��������������\n"
        );
        set("gender", "����");
        set("age", 27);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 24);
        set("con", 28);
        set("dex", 28);

        set("max_kee", 1000);
        set("max_gin", 1000);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 50);
        set("combat_exp", 15000);
        set("score", 7000);

        set_skill("force", 60);
        set_skill("huashan-neigong", 70);
        set_skill("dodge", 70);
        set_skill("huashan-shenfa", 70);
        set_skill("cuff", 60);
        set_skill("poyu-quan", 60);
        set_skill("parry", 80);
        set_skill("sword", 60);
        set_skill("huashan-jianfa", 60);
//      set_skill("literate", 50);

        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("cuff", "poyu-quan");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
        prepare_skill("cuff", "poyu-quan");

        create_family("��ɽ��", 19, "����");


        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();

}

void attempt_apprentice(object ob)
{
        command("say ʦ��û������ͽ��");
        return;
}

void init()
{

        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        if (present("letter paper", this_player()))
        {
                me->set_leader(ob);
        	call_out("kill_ob", 1, this_player());
        	command("say ��������ʦ�������ţ��������ɽ����������");
        }
}
