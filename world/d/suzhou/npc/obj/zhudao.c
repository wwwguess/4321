//OBJECT:/d/suzhou/npc/obj/zhudao.c 
//by dwolf
//9711.5
        
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(RED"��"NOR, ({ "zhu dao", "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ���񵶣��ھֵ��ӵ���ϰ������\n");
		set("value", 10);
		set("material", "wood");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(2);
	setup();
}
