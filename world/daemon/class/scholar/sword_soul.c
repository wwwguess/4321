// sword_soul.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name( HIW "��Ȫ����" NOR, ({ "sword soul", "soul" }) );
	set("long", "һ���ߴ�����Σ�ֻ��������������ɫ�Ĺ�â���������ݶ���͸���ģ�\n");
	set("age", 19);
	set("gender", "Ů��");
	set("attitude", "heroism");

	set("max_gin", 2000);
	set("max_kee", 2000);
	set("max_sen", 2000);

	set("str", 80);
	set("con", 70);
	set("cor", 40);
	set("spi", 40);
	set("int", 20);
	set("cps", 90);
	set("kar", 80);
	set("per", 50);

	set_temp("apply/attack", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 120);
	set_temp("apply/armor_vs_force", 1000);

	set_skill("sword", 150);
	set_skill("parry", 150);

	set("combat_exp", 300000);

	setup();
}

void chant()
{
	call_out("chant_sword", 20, 1);
}

static void chant_sword(int stage)
{
	switch(stage) {
		case 1:
			command("say ����ָ�� ...");
			call_out("chant_sword", 20, 2);
			break;
		case 2:
			command("say �������� ...");
			call_out("chant_sword", 20, 3);
			break;
		case 3:
			command("say ��â�ι� ...");
			call_out("chant_sword", 20, 4);
			break;
		case 4:
			command("say �������⣡");
			message_vision("һ����������ס$N�����ˡ���һ����$N�������ֱ�������һЩ��\n", this_object());
			add("combat_exp", 100000);
			call_out("chant_sword", 60, 1);
			break;
	}
}
