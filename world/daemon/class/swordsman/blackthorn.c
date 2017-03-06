// blackthorn.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name( HIW "���ս�" NOR, ({ "blackthorn sword", "blackthorn", "sword" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"����һ��ͨ����ڵ��ؽ������������˼���ĵ�����������������\n"
			"�����ഫ�ı�������˵��ѽ�ɱ�˲�մѪ����Զ����ɱ����\n");
		set("value", 2400);
		set("material", "blacksteel");
		set("replica_ob", "/obj/longsword");
		set("wield_msg", "ֻ������쬡���һ����$N�������Ѿ�����һ�Ѻ�������ı�������$n��\n");
		set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
		set("weapon_prop/courage", 3);
		set("weapon_prop/defense", 5);
		set("rigidity", 30);
	}
	init_sword(58);
	setup();
}
