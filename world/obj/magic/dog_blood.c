// dog_blood.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("�ڹ�Ѫ", ({ "dog blood", "blood" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ƿ");
		set("long",
			"�������������õĺڹ�Ѫ(װ����Ͳ��)���Ѻڹ�Ѫ��(splash)�ڹ������\n"
			"��������൱����˺���\n");
		set("value", 300);
		set("material", "bamboo");
	}
	setup();
}

void init()
{
	add_action("do_splash", "splash");
}

int do_splash(string arg)
{
	object ob;
	string msg;
	int ghost_hit;

	if( !arg || arg=="" )
		return notify_fail("��Ҫ���ڹ�Ѫ����˭���ϣ�\n");
	ob = present(arg, environment(this_player()));
	if( !ob || !ob->is_character() )
		return notify_fail("����û������ˡ�\n");
	msg = HIR "\n$N�ο�װ���ڹ�Ѫ����Ͳ������׼$n���˹�ȥ��\n\n" NOR;
	if( random(ob->query("combat_exp")) > (int)this_player()->query("combat_exp") )
		msg += "����$n�ܿ�����˿�ȥ��һ��Ҳû�б�������\n";
	else {
		msg += "ֻ������������һ����$n���ڹ�Ѫ��������\n";
		if( ob->is_ghost() || ob->is_undead() ) {
			msg += "��$n�����İ������У�$p���ϱ��ڹ�Ѫ�ܵ��Ĳ�λ����������̣�\n";
			ob->receive_wound("kee", 120);
			ghost_hit = 1; // �д򵽹�
		}
	}
	message_vision(msg, this_player(), ob);
	// Ҫ�Է��ǹ�ŻῪ��
	if( !ob->is_killing(this_player()->query("id")) && ghost_hit )
		ob->kill_ob(this_player());
	destruct(this_object());
	return 1;
}

