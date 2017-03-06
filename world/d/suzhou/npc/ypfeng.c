//NPC: /d/suzhou/npc/ypfeng.c

#include <ansi.h>

inherit NPC;

void heal();
void create()
{
        set_name(MAG"���ŷ�"NOR, ({ "yang paifeng", "yang" }));
        set("title", CYN "����" NOR + YEL "����" NOR);
        set("gender", "Ů��");
        set("age", 23);
        set("str", 35);
        set("dex", 26);
	set("per", 25);
	set("ping", 4);

        set("long", "���ŷ�������������Ů������˵�����¹�򣶼���䵱������ĸ�ͽ��\n");
        set("combat_exp", 200000);
        set("shen_type", 1);
        set("attitude", "heroism");

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

	set_skill("cuff", 70);
        set_skill("force", 70);
	set_skill("taiji-shengong", 60);
        set_skill("sword", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
	set_skill("tiyunzong", 70);
	set_skill("taiji-quan", 70);
    	set_skill("taiji-jian",50);

        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
	map_skill("force", "taiji-shengong");

	prepare_skill("cuff", "taiji-quan");

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 20);

        set("max_kee", 700);
        set("force", 700);
        set("max_force", 700);
        set("force_factor", 20);

        setup();
        carry_object(__DIR__"obj/gangjian")->wield();
        carry_object(__DIR__"obj/tiejia")->wear();
}

int accept_fight(object me)
{
        command("say �����Ҿ�δ�ͽ����˶��ֹ����ˣ����վͺ������档");
        return 0;
}
int recognize_apprentice(object ob)
{
        if ( (string)ob->query("family/family_name")=="��͢" && (string)ob->query("wen-wu")=="wu")
                return 1;
	else
		return 0;
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_qi") < ob->query("max_kee"))
        {
                command("exert heal");
                command("enforce 20");
                return;
        }

        if (ob->query("kee") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_jing"))
                command("exert regenerate");

        return;
}
