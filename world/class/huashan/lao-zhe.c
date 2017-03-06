// Npc: /kungfu/class/shaolin/hui-zhen.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("������", ({
                "gao laozhe",
                "laozhe",
        }));
        set("long",
                "����һλ��ĸߴ�����ߣ���һ�Ҳ�������\n"
                "̫��Ѩ΢͹��˫Ŀ��������\n"
        );

        set("gender", "����");
        set("attitude", "friendly");

        set("age", 50);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_kee", 600);
        set("max_gin", 500);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 100);
        set("combat_exp", 50000);
        set("score", 100);

        set_skill("force", 100);
        set_skill("huashan-neigong", 80);
        set_skill("dodge", 80);
        set_skill("huashan-shenfa", 80);
        set_skill("cuff", 90);
        set_skill("poyu-quan", 90);
        set_skill("strike", 70);
        set_skill("hunyuan-zhang", 70);
        set_skill("sword", 80);
        set_skill("huashan-jianfa", 80);
        set_skill("parry", 80);
        set_skill("literate", 100);

        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("sword", "huashan-jianfa");
        map_skill("parry", "huashan-jianfa");

        prepare_skill("cuff", "poyu-quan");
        prepare_skill("strike", "hunyuan-zhang");

        create_family("��ɽ��", 17, "����");

        setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();
}
void init()
{
        mapping mine;
        object me, room;

        me = this_player();

        if (!mapp(mine = me->query("family")))
                return;


        if( (mapp(mine = me->query("family")) && mine["family_name"] != "��ɽ��"))
      
        {
                  command("say �󵨿�ͽ������˽����ɽ���ң�����!\n");
                  call_out("kill_ob", 0, this_player());
                  COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
                  return;
        }

        return;
}
