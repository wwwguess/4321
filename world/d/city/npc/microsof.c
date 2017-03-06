// microsof.c
#include <ansi.h>

inherit NPC;

string ask_me(object who); 

void create()
{
	set_name("����û����", ({ "microsof" }) );
	set("title", "Ǯׯ�ϰ�");
	set("gender", "����" );
	set("age", 30);

	set("str", 22);
	set("cor", 25);
	set("cps", 25);
	set("int", 26);
	set("per", 25);
	set("con", 24);
	set("spi", 25);
	set("kar", 25);

	set("long",
		"����û�����Ǹ��������൱�����������ˣ����ı���������κ���\n"
		"��֪����ʲô���ĵ����⣬һҹ֮�䱩������������Ǯׯ���𽥵�\n"
		"������Ǯׯȫ�������ˣ���ʦ�ľ�������ĺܶ��������ǳ���������\n"
		"����������ºš���Ҷ�֪����С�Ǽ���������˭Ҳ��ȥ������\n");

	set("combat_exp", 100000);
	set("attitude", "friendly");
	set("pursuer", 1);
	set("env/wimpy", 70);

	set("max_atman", 1000);		set("atman", 1000);		set("atman_factor", 3);
	set("max_force", 1000);		set("force", 1000);		set("force_factor", 3);
	set("max_mana", 1000);		set("mana", 1000);		set("mana_factor", 3);

	set("chat_chance", 15 );
	set("chat_msg", ({
		CYN "����û����ѹ��ɤ������˵������������������ˣ���֪����ÿ���������ٽ����𣿡�\n"
 NOR,
		CYN "����û�����޺޵�˵�����ߣ���Ҫ��NTҲ����������֮����ô�죡��\n" NOR,
		(: exert_function, "powerfade" :),
		}) );

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		CYN "����û����ͻȻ�����۵�����ü����������������\n" NOR,
		CYN "����û�����ĺ����������������ֽС�\n" NOR,
		CYN "����û���������Ȼ���������������������������Լ����£������޹ء�\n" NOR,
		CYN "����û������Ȼ�ǺǺǵ�Ц��������ȴ��֪����ЦЩʲô....\n" NOR,
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

	add_money("gold", 10);
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
			say( "����û����һ�������ۣ���֪�������ʲô�����⡣\n");
			break;
		case 1:
			say( "����û����˵������λ" + RANK_D->query_respect(ob)
			 + "����Ǯ����Ҫ���İ���\n");
			break;
		case 2:
			say( "����û����˵������λ" + RANK_D->query_respect(ob)
			 + "��Ǯ��Ҫ�Լ����������\n");
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
