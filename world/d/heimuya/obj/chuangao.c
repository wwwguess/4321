// chuangao.c
// write by dfbb@hero  
// Tue Dec 26 18:10:16 CST 1995


#include <weapon.h>
inherit SPEAR;

void create()
{
	set_name("����", ({ "chuangao", "gao" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ����ͨ�Ĵ���,�������񷤵�\n");
		set("value", 100);
		set("material", "zhu");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n����񷤡�\n");
	}
	init_spear(5);
	setup();
}
