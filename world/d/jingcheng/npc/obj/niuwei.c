// niuwei.c ţβ

#include <weapon.h>
inherit WHIP;
inherit F_FOOD;

void create()
{
	set_name("ţβ", ({ "niu wei", "wei" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ţ��β�͡�\n");
		set("unit", "��");
		set("value", 10);
		set("food_remaining", 2);
		set("food_supply", 10);
		set("wield_msg", "$Nץ��һ��$n���������е�������\n");
		}
	init_whip(1);
	setup();
}

