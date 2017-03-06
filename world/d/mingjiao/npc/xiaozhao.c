// xiaozhao

#include <ansi.h>

inherit NPC;

void heal();
void create()
{
	set_name("С��", ({ "xiao zhao", "zhao" }));
	set("long", 
		"������ڵ�Ѿ�ߣ�˫�ֱ�һ���������ţ�������˼��\n");
		
        set("title", CYN "���" NOR + MAG "Ѿ��" NOR);
       
	set("gender", "Ů��");
	set("age", 16);
	set("shen_type", 1);

	set("force", 800);
	set("max_force", 800);
	set("max_kee", 800);
	set("max_gin", 700);
	set("force_factor", 10);
	set("per", 30);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

	set_skill("force", 50);
	set_skill("taiji-shengong", 40);
	set_skill("cuff", 50);
	set_skill("taiji-quan", 40);
	set_skill("dodge", 60);
	set_skill("tiyunzong", 50);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji-jian", 40);

	map_skill("sword", "taiji-jian");
	map_skill("parry", "taiji-jian");
	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji-shengong");
	map_skill("cuff", "taiji-quan");

	prepare_skill("cuff", "taiji-quan");

	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);

	setup();
	
	
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_qi") < ob->query("max_kee"))
        {
                command("exert heal");
                command("enforce 10");
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

