// banker.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("��ϧ��", ({ "annihir" }) );
	set("title", "Ǯׯ�ϰ�");
	set("gender", "����" );
	set("age", 26);

	set("str", 22);
	set("cor", 30);
	set("cps", 30);
	set("int", 26);
	set("per", 23);
	set("con", 24);
	set("spi", 30);
	set("kar", 25);

	set("long",
		"��ϧ���Ǹ��������൱˹�ĵ������ˣ�������ʱ�����Щ�Ĳ����ɵ�\n"
		"���ӣ�ѩͤ��ľ���԰�ϧ�Ƕ������е�����Ī��ĸо���Ϊʲô��\n"
		"����������Ϊһ�Ҵ�Ǯׯ���ϰ壬������һ��ϡ��Źֵ��书\����\n"
		"�Ұ�ϧ���ƺ������񵭣�������Щ���ߵķ�ǣ�ֻҪ���˲�ȥ������\n"
		"��Ҳ������ȥ�������ˡ�\n");

	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("pursuer", 1);
	set("env/wimpy", 70);

	set("max_atman", 1000);		set("atman", 1000);		set("atman_factor", 3);
	set("max_force", 1000);		set("force", 1000);		set("force_factor", 3);
	set("max_mana", 1000);		set("mana", 1000);		set("mana_factor", 3);

	set("chat_chance", 15 );
	set("chat_msg", ({
//		(: random_move :),
		(: exert_function, "powerfade" :),
	}) );

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		CYN "��ϧ����Ц��Ц�������㣬���ϵ���������Ź֣���֪������Щʲô��\n" NOR,
		CYN "��ϧ�ǵ���Ӱ����һ�£��ƺ��������ϸ�����Ѩ����һ�£�����Ҳ��\����Ĵ����\n" NOR,
		CYN "��ϧ�������Ȼ���������������������������Լ����£������޹ء�\n" NOR,
		CYN "��ϧ�Ǻ�Ȼ�ǺǺǵ�Ц��������ȴ��֪����ЦЩʲô....\n" NOR,
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

int accept_fight(object me)
{
	command("say ��... Ҫ������ɣ����ǽ�����û��˼��");
	command("grin");
	kill_ob(me);
	return 1;
}
