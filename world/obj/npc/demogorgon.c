// demongorgon.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name( HIW "�������" NOR, ({ "demogorgon" }) );
	set("long",
		"������������ư���վ������ǰ�����ߴ��������һ��������Ϣ��\n"
		"����ɱ����ѹ���㼸����������������������ƺ���һ�������ڸ�\n"
		"���㣺�� �� �� ������\n");

	set("age", 7006);
	set("pursuer", 1);

	set("max_gin", 5000);
	set("max_kee", 5000);
	set("max_sen", 5000);

	set("max_atman", 9999);
	set("atman", 9999);
	set("max_force", 5000);
	set("force", 5000);
	set("max_mana", 5000);
	set("mana", 5000);

	set("str", 100);
	set("cor", 100);
	set("cps", 100);
	set("spi", 100);
	set("int", 100);
	set("con", 100);
	set("kar", 0);
	set("per", 0);

	set("combat_exp", 5000000);

	set_skill("staff", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	setup();

	carry_object(__DIR__"obj/demon_staff")->wield();
}

void start_shutdown()
{
	if( geteuid(previous_object()) != ROOT_UID ) return;

	message("system",
		HIR "\n����������д���һ����µ����� ....\n\n"
		HIW	"�������" HIR "����������������ȵ���\n\n"
			"\t\tȫ �� �� �� �� �� �� �� �� �� ��\n\n"
			"\t\t������ʮ������ڰ��ҵ�ͷ­������ ��\n\n"
			"\t\t�� Ȼ �� �� ..... �� .. �� ��\n\n" NOR,
		users() );
	call_out("countdown", 60, 15);
}

 void countdown(int min)
{
	min--;
	if( min ) {
		message("system",
			HIW "\n�������" HIR "����������������ȵ���\n\n"
				"\t\t���ǻ���" + chinese_number(min) + "���ӵ�ʱ�佻���ҵ�ͷ­��\n\n"
				"\t\t������Ҫ�������ġ��͡������ҡ����������ϡ��ɡ���\n\n" NOR,
			users() );
		call_out("countdown", 60, min);
	} else {
		message("system",
			HIW "\n�������" HIR "����������������ȵ���\n\n"
				"\t\t�ɺ�.....���ǿɺ�....\n\n"
				"\t\t���찡�� ��ذ���  ���󰡡�  ��������\n\n" NOR,
			users() );
		call_out("do_shutdown", 3);
	}
}

 void do_shutdown()
{
	message("system",
		HIW "\n\n�������" HIR "����������������ȵ���\n\n"
		HIW "\t\tͨ ͨ �� �� һ �� �� �� �� �� �������� ��\n\n"
		HIR "\t\t����һ�ϣ�������̱��Ѫ�죬��....����ǰ��һ�ж����Ѫ��...\n\n"
			"\t\t���е�һ�ж���˲�������....\n\n"
			"\t\tȻ�������ǰ��һƬ�ڰ�....��ֹ���ĺڰ�....\n\n" NOR,
		users() );
	shutdown(0);
}

void die()
{
	object ob;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);

	if( !ob ) return;

	message("system",
		HIR "\n\n������һ�������ߺޡ����֡���Ұ�ް���������쳹������ա�\n\n"
		HIW "�������" HIR "˻�Ƶغ������ɶ��" + ob->name(1) + "����һ���ᱨ��ġ�����\n\n"
			"Ȼ��һ����ɫ�����Х�������ƶˣ�����ָֻ���������\n\n" NOR,
		users() );
	destruct(this_object());
}
