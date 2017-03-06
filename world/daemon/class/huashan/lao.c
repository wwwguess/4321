// laodenuo.c �͵�ŵ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("�͵�ŵ", ({ "lao denuo", "lao" }));
        set("title",GRN "��ɽ��" NOR + YEL +"����" NOR);
        set("long",
                "����������Ⱥ�Ķ������ϵ�ŵ��\n"
                "����ͱȴ����������ֻ�Ǵ���Ͷʦ��ֻ�����϶��ˡ�\n");
        set("gender", "����");
        set("age", 32);
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
        set("score", 6000);

        set_skill("force", 80);
        set_skill("huashan-neigong", 70);
        set_skill("dodge", 70);
        set_skill("huashan-shenfa", 70);
	set_skill("cuff", 40);
	set_skill("poyu-quan", 30);
        set_skill("parry", 80);
        set_skill("sword", 80);
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
	if (present("zixia miji", this_player()))
        {
		me->set_leader(ob);
        call_out("kill_ob", 1, this_player());
        set("shen_type", -1);
        set("force_factor", 60);
        set("combat_exp", 20000);
        set("score", 6000);

        set_skill("force", 80);
        set_skill("zixia-shengong", 70);
        set_skill("dodge", 90);
        set_skill("huashan-shenfa", 80);
        set_skill("cuff", 100);
	set_skill("poyu-quan", 50);
        set_skill("parry", 90);
        set_skill("sword", 90);
        set_skill("huashan-jianfa", 80);

        map_skill("force", "zixia-shengong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("cuff", "poyu-quan");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

	prepare_skill("cuff", "poyu-quan");

	command("say ������ʦ�����ؼ����������ɽ����������");
        }
}
