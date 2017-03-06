// xiaosong.c ������
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "song qingshu", "song" }));
	set("title",RED "�䵱" NOR + GRN "����" NOR);
        set("long",
                "��������Զ�ŵĶ��������顣\n"
                "�������ʮ�꣬�����䵱�������г�����͵����\n");
        set("gender", "����");
        set("age", 20);
        set("attitude", "peaceful");
        set("per", 29);
        set("str", 25);
        set("int", 28);
        set("con", 25);
        set("kar", 25);

        set("max_kee", 1000);
        set("max_gin", 500);
        set("force", 1200);
        set("max_force", 1200);
        set("force_factor", 40);
        set("combat_exp", 700000);
        set("score", 10000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set_skill("force", 100);
        set_skill("taiji-shengong", 90);
        set_skill("dodge", 90);
        set_skill("tiyunzong", 90);
        set_skill("cuff", 70);
        set_skill("taiji-quan", 80);
        set_skill("parry", 70);
        set_skill("sword", 100);
        set_skill("taiji-jian", 100);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");

        create_family("�䵱��", 3, "����");

        setup();
        carry_object("/obj/weapon/changjian")->wield();
}
void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();

        if (interactive(ob)
        && !environment(ob)->query("no_fight")
        && ( (fam = ob->query("family")) 
	&& fam["family_name"] == "�䵱��" 
	&& ob->query("shen")< -100))
        {
                command("say ����Ϊ�䵱���ӣ�ȷɱ���������ˣ��������ɣ�����\n");
                me->set_leader(ob);
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}
