// ruler.c

#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name( "���³�", ({ "ruler" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������õĳ��ӣ���һ��Ŀ�Щ��\n");
		set("value", 30);
		set("material", "wood");
		set("wield_msg", "$N�ó�һ��$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_dagger(2);
	setup();
}
