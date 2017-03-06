#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����", ({ "shi wei", "shi", "wei" }));
        set("title", YEL"�ʳ�����"NOR);
	set("gender", "����");
	set("age", random(10) + 20);
	set("str", 30);
	set("dex", 30);
	set("long", "��վ�������ȷ��˵���������硣\n");
	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("pestle", 80);
	set_skill("xiangmo-chu", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);

	map_skill("pestle", "xiangmo-chu");
	map_skill("parry", "xiangmo-chu");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("force", 800); 
	set("max_force", 800);
	set("force_factor", 50);

	setup();
	carry_object("/obj/weapon/xiangmochu")->wield();
	carry_object("/d/yueyang/npc/obj/tiejia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
