// banker.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);
void greeting(object ob);

void create()
{
	set_name("����", ({ "chp" }) );
//	set("title", "��");
	set("gender", "����" );
	set("age", 26);

	set("str", 22);
	set("cor", 30);
       set("cps", 30);
	set("int", 26);
	set("per", 23);
	set("con", 24);
	set("long", "�����Ǹ��������൱˹�ĵ������ˣ�������ʱ�����Щ�Ĳ����ɵ�\n"
                "���ӣ�����Щ���ߵķ��\n");
set("combat_exp", 200000);
	set("attitude", "friendly");
	set("pursuer", 1);
	set("env/wimpy", 70);

	set("max_atman", 1000);		set("atman", 1000);		set("atman_factor", 3);
	set("max_force", 1000);		set("force", 1000);		set("force_factor", 3);

        set("chat_chance_combat", 40);
	set("max_mana", 1000);		set("mana", 1000);		set("mana_factor", 3);

        set("chat_msg_combat", ({
                CYN "������Ц��Ц�������㣬���ϵ���������Ź֣���֪������Щʲ
ô��\n" NOR,
                CYN "���µ���Ӱ����һ�£��ƺ��������ϸ�����Ѩ����һ�£�����Ҳ
��\����Ĵ����\n" NOR,
                CYN "���������Ȼ���������������������������Լ���Ӣ�﷭���£������޹�
��\n" NOR,
                CYN "���º�Ȼ�ǺǺǵ�Ц��������ȴ��֪����ЦЩʲô....\n" NOR,
                (: perform_action, "sword.counterattack" :),
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
                
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("celestrike", 100);
	set_skill("celestial", 100);
	set_skill("fonxansword", 100);
	set_skill("six-chaos-sword", 100);
	set_skill("chaos-steps", 100);
	set_skill("spells", 100);
	set_skill("necromancy", 100);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("dodge", "chaos-steps");
	map_skill("sword", "fonxansword");
	map_skill("spells", "necromancy");
	map_skill("sword", "fonxansword");
	
	setup();
	
	carry_object("/obj/longsword")->wield();
	carry_object("/obj/cloth")->wear();

	//add_money("gold", 10);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "����Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "������ЪϢһ�°ɡ�\n");
                        break;
                case 1:
                        say( "������ë��Ĩ��Ĩͷ�ϵĺ���˵������λ" + RANK_D->query_respect(ob)
                                + "�����ҷ��뼸ҳӢ�����ϰɡ�\n");
                        break;
                case 2:
                        say( "����˵������λ" + RANK_D->query_respect(ob)
                                + "����ʲô���������ѽ��\n");
                        break;
        }
}

int accept_fight(object me)
{
	command("say ��... Ҫ������ɣ����ǽ�����û��˼��");
	command("grin");
	kill_ob(me);
	return 1;
}
